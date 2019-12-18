// https://leetcode-cn.com/problems/longest-palindromic-substring/

// 暴力法优化，动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }
        // state 表示从 i到 j的子串是回文
        vector<vector<bool>> state(s.length(), vector<bool>(s.length(), false));
        string maxPalidrome = s.substr(0, 1);
        for (int j = 1; j < s.length(); j++) {
            for (int i = 0; i < j; i++)  {
                // i到 j的子串长度为2、3或大于3且中间部分为回文，此时若两头字符相等则子串为回文
                state[i][j] = (((j - i) == 1 || (j - i) == 2 || state[i + 1][j - 1]) && (s[i] == s[j]));
                if (state[i][j] && (j - i + 1) > maxPalidrome.length()) {
                    maxPalidrome = s.substr(i, j - i + 1);
                }
            }
        }
        return maxPalidrome;
    }
};

// 中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = (len1 >= len2) ? len1 : len2;
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s.at(left) == s.at(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};