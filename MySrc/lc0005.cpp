// https://leetcode-cn.com/problems/longest-palindromic-substring/

// 暴力法优化
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }
        vector<vector<bool> > stateRecord;
        vector<bool> temp(s.length());
        stateRecord.resize(s.length(), temp);

        string maxPalidrome = s.substr(0, 1);
        for (int j = 1; j < s.length(); j++) {
            for (int i = 0; i < j; i++)  {
                stateRecord[i][j] = (((j - i) == 1 || (j - i) == 2 || stateRecord[i + 1][j - 1]) && (s.at(i) == s.at(j)));
                if (stateRecord[i][j] && (j - i +1) > maxPalidrome.length()) {
                    maxPalidrome = s.substr(i, j - i + 1);
                }
            }
        }
        return maxPalidrome;
    }
};