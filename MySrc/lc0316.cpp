// https://leetcode-cn.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (res.find(s[i]) == string::npos) {
                for (int j = res.length() - 1; j >= 0; j--) {
                    if (res[j] > s[i] && s.find(res[j], i + 1) != string::npos) {
                        res.erase(j);
                        continue;
                    }
                    break;
                }
                res += s[i];
            }
        }
        return res;
    }
};