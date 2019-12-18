// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/

// string 查找函数
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }
        int maxLen = 0;
        int index = 0;
        for (int i = 1; i < s.length(); i++) {
            // 从 index处开始向右查找
            string::size_type pos = s.find(s[i], index);
            // pos 处找到与 s[i]重复的字符且 pos 在 i 的左侧
            if (pos != string::npos && pos < i) {
                // index 到 i的距离即为一段无重复子串的长度
                if (i - index > maxLen) {
                    maxLen = i - index;
                }
                // index 移动的 pos的右侧继续查找
                index = pos + 1;
                continue;
            } // 未找到或 pos位于 i 右侧的情况暂不考虑
        }
        // index 停止移动时，其到最右端也是一段无重复子串
        if (s.length() - index > maxLen) {
            maxLen = s.length() - index;
        }
        return maxLen;
    }
};