// https://leetcode-cn.com/problems/trapping-rain-water/

// 按列法：逐个计算每根柱子上面可以存多少水
// auto, max_element 用法
class Solution {
public:
    int trap(vector<int>& height) {
        // 至少3根柱子才能接水
        if(height.size() < 3) {
            return 0;
        }
        int sum = 0;
        int curLMax = height[0];
        int curRMax = 0;
        for (size_t i = 0; i < height.size() - 1; i++) {
            if (height[i] > curLMax) {
                curLMax = height[i];
            }
            if (height[i] >= curRMax) {
                auto rMax = max_element(height.begin() + i + 1, height.end());
                curRMax = *rMax;
            }
            // 计算当前柱子的存水量
            if (height[i] < curLMax && height[i] < curRMax) {
                sum += min(curLMax, curRMax) - height[i];
            }
        }
        return sum;
    }
};
