// https://leetcode-cn.com/problems/regular-expression-matching/

// not completed
class Solution {

public:
    bool isMatch(string s, string p) {
        if (s.length() == 0 || p.length() == 0) {
            return false;
        }
        vector<vector<int>> matchInfo(s.length(), vector<int>(p.length(), -1));
        matchInfo[0][0] = (s[0] == p[0] || p[0] == '.');
        if (p.length() > 1) {
            matchInfo[0][1] = (s[0] == p[0] || p[0] == '.') && p[1] == '*';            
        }
        if (s.length() > 1) {
            matchInfo[1][0] = 0;            
        }

        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j < p.length(); j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    matchInfo[i][j] = matchInfo[i - 1][j - 1];
                } else if (p[j] != '*') {
                    matchInfo[i][j] = 0;
                    break;
                } else {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        // dp[i][j] = dp[i-1][j] // 多个字符匹配的情况	
                        // dp[i][j] = dp[i][j-1] // 单个字符匹配的情况
                        // dp[i][j] = dp[i][j-2] // 没有匹配的情况
                        matchInfo[i][j] = (matchInfo[i][j - 1] || matchInfo[i - 1][j]);
                        if (j - 2 >= 0) {
                            matchInfo[i][j] = (matchInfo[i][j - 1] || matchInfo[i][j - 2]);
                        }
                    } else {
                        matchInfo[i][j] = matchInfo[i][j - 1];
                    }
                }
            }
        }
        return matchInfo[s.length() - 1][p.length() - 1];
    }
};