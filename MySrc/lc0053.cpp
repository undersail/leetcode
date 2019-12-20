// https://leetcode-cn.com/problems/maximum-subarray/

// 顺序遍历，基本算数
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int sum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
