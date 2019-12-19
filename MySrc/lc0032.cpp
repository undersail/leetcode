// https://leetcode-cn.com/problems/longest-valid-parentheses/

// 栈操作
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxValidSize = 0;
        stack<int> indexs;
        indexs.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') {
                indexs.push(i);
            } else {
                indexs.pop();
                if (indexs.empty()) {
                    indexs.push(i);
                }
            }
            maxValidSize = max(maxValidSize, i - indexs.top());
        }
        return maxValidSize;
    }
};