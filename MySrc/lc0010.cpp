// https://leetcode-cn.com/problems/regular-expression-matching/

// 动态规划
// 当前结果：解答错误，部分用例通过
class Solution {

public:
    bool isMatch(string s, string p) {
        // 特殊情况
        if (s.length() == 0 || p.length() == 0) {
            return false;
        }
        // matchInfo记录 s的前 i子串 p的前 j 字串的匹配情况
        vector<vector<bool>> matchInfo(s.length(), vector<bool>(p.length(), false));
        matchInfo[0][0] = (s[0] == p[0] || p[0] == '.');
        // 初始化边界条件
        for (int i = 1; i < s.length(); i++) {
            matchInfo[i][0] = false;
        }
        for (int j = 1; j < p.length(); j++) {
            matchInfo[0][j] = (matchInfo[0][j - 1] && p[j] == '*');
            if (j - 2 >= 0) {
                matchInfo[0][j] = matchInfo[0][j] || matchInfo[0][j - 2];  // *号匹配零个字符的情况
            }        
        }

        for (int i = 1; i < s.length(); i++) {
            for (int j = 1; j < p.length(); j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    matchInfo[i][j] = matchInfo[i - 1][j - 1];
                } else if (p[j] != '*') {
                    matchInfo[i][j] = false;
                    break;
                } else {
                    // p[j]为*号的情况
                    //if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        // dp[i][j] = dp[i][j-1] // *号匹配零个字符的情况
                        // dp[i][j] = dp[i-1][j] // *号匹配多个字符的情况	
                        
                        // dp[i][j] = dp[i][j-2] // 没有匹配的情况
                        matchInfo[i][j] = matchInfo[i][j - 1] ||  // *号匹配零个字符的情况
                            ((matchInfo[i - 1][j]) && (s[i] == p[j - 1]) || p[j - 1] == '.');    // *号匹配多个字符的情况	
                        if (j - 2 >= 0) {
                            matchInfo[i][j] = matchInfo[i][j] || matchInfo[i][j - 2];  // *号匹配零个字符的情况
                        }
                    //} else {
                    //    matchInfo[i][j] = matchInfo[i][j - 1];
                    //}
                }
            }
        }
        return matchInfo[s.length() - 1][p.length() - 1];
    }
};
