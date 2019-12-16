// https://leetcode-cn.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string longestPre = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char cur = strs[0].at(i);
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j].at(i) != cur) {
                    return longestPre;
                }
            }
            stringstream stream;
            stream << cur;
            longestPre += stream.str();
        }
        return longestPre;
    }
};