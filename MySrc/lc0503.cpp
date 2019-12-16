// https://leetcode-cn.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> greaters;
        //vector<int> indexs;
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            for (j = i + 1; j < nums.size() + i; j++) {
                int jj = j % nums.size();
                if (nums[jj] > nums[i]) {
                    greaters.push_back(nums[jj]);
                    //indexs.push_back(jj);
                    break;
                }
            }
            if (j == nums.size() + i) {
                greaters.push_back(-1);
                //indexs.push_back(-1);
            }
        }
        return greaters;
    }
};