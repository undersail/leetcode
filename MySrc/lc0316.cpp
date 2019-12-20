// https://leetcode-cn.com/problems/remove-duplicate-letters/

// 字符串遍历、查找
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (res.find(s[i]) == string::npos) {
                for (int j = res.length() - 1; j >= 0; j--) {
                    // s[i]的右侧存在与res[j]相同的字符，且res[j]更大，则删除res[j]及其右侧字符
                    if (res[j] > s[i] && s.find(res[j], i + 1) != string::npos) {
                        res.erase(j);
                        continue;
                    }
                    break;
                }
                // s[i]添加到res结尾
                res += s[i];
            }
        }
        return res;
    }
};
