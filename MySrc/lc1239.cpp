// https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// 位图，递归，深度优先搜索
const int MAX_LETTER = 26;
struct Bitmap{
    unsigned int mask;
    int len;
    Bitmap(int m, int l) {
        mask = m;
        len = l;
    }
};

class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int size = arr.size();
        vector<Bitmap> bitmaps;
        for (auto s : arr) {
            Bitmap bitmap(0, 0);
            // s的长度不超过26，所以可以转换为uint类型位图（可容纳32位）
            if (Str2Bitmap(s, bitmap)) {
                // 如果没有重复，将其mask和len计入位图列表
                bitmaps.push_back(bitmap);
            }  // 如果s内部本身有重复，跟任何其他子串都不能形成有效组合，直接忽略
        }
        // 用于存放最长有效长度以及对应的mask。
        Bitmap result(0, 0);
        // 进行dfs深度遍历，从index 0 开始，直到最后一个数组元素结束
        return GetMaxLen(bitmaps, 0, result);
    }

private:
    int GetMaxLen(vector<Bitmap> &bitmaps, int index, Bitmap result) {
        // 遍历结束条件
        if (index >= bitmaps.size()) {
            return result.len;
        }
        // maxLen表示[index, last]的有效最大长度（同时也是函数返回值）
        // 递归计算分为两种情况：
        // case 1, 当前字符串不加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果一致
        int maxLen = GetMaxLen(bitmaps, index + 1, result);
        // case 2， 当前字符串加入结果的话， maxLen[index, last]与maxLen[index+1, last]的结果是否一致需要分两种情况：
        if ((result.mask & (bitmaps[index].mask)) == 0) {
            // case 2.1 如果当前字符串与结果字符串不重复： 说明是有效的，需要刷新后继续Dfs遍历
            // 做法： 将当前字符串的len和mask更新到结果中。
            result.mask |= bitmaps[index].mask;
            result.len += bitmaps[index].len;
            // 调用Dfs获取当前结果与与[index+1, last]各元素最长的有效组合 长度lenWithCur
            int lenWithCur = GetMaxLen(bitmaps, index + 1, result);
            // 如果结果中加入当前字符(arr[index])比不加入结果的情况更好(lenWithCur > maxLen),则更新返回值maxLen
            if (lenWithCur > maxLen) {
                maxLen = lenWithCur;
            }
        } /* else {
            // case 2.2 如果加入当前字符串arr[index]与已经结果result.mask有重复：
            // 说明结果是无效的， 无需再深入遍历了
        } */
        return maxLen;
    }

    bool Str2Bitmap(string &s, Bitmap &bitmap) {
        unsigned int ret = 0;
        for (auto c : s) {
            unsigned int mask = 1 << (c-'a');
            if (mask & ret) {
                return false;
            }
            ret |= mask;
        }
        bitmap.mask = ret;
        bitmap.len = s.size();
        return true;
    }
};
