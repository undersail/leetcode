// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) {
            return s.length();
        }
        int maxLen = 0;
        int index = 0;
        for (int i = 1; i < s.length(); i++) {
            string::size_type pos = s.find(s[i], index);
            if (pos < i) {
                if (i - index > maxLen) {
                    maxLen = i - index;
                }
                index = pos + 1;
                continue;
            }
        }
        if (s.length() - index > maxLen) {
            maxLen = s.length() - index;
        }
        return maxLen;
    }
};