// https://leetcode-cn.com/problems/first-missing-positive/

// 数学知识
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        for(i = 0; i < nums.size(); i++){
            while(nums[i] != i + 1){
                if(nums[i] < nums.size() && nums[i] > 0 && nums[i] != nums[nums[i] - 1]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }
                else{
                    break;
                }
            }            
        }
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                break;
            }
        }
        return (i + 1);
    }
};