// https://leetcode-cn.com/problems/next-greater-element-ii/

// 暴力解法
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> greaters;
        // 预先计算size节省一半时间
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int j = 0;
            // 关键点：循环数组的处理
            for (j = i + 1; j < size + i; j++) {
                int jj = j % size;
                if (nums[jj] > nums[i]) {
                    greaters.push_back(nums[jj]);
                    break;
                }
            }
            if (j == size + i) {
                greaters.push_back(-1);
            }
        }
        return greaters;
    }
};
