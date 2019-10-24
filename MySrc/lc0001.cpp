// https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    index1 = i;
                    index2 = j;
                    break;
                }
            }
        }
        vector<int> res;
        res.push_back(index1);
        res.push_back(index2);
        return res;
    }
};