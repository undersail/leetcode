// https://leetcode-cn.com/problems/guess-numbers/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return (bool)(!(guess[0] - answer[0])) +  (bool)(!(guess[1] - answer[1])) + (bool)(!(guess[2] - answer[2]));
    }
};