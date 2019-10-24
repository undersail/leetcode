// https://leetcode-cn.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
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
            if (curLMax > height[i] && curRMax > height[i]) {
                sum += min(curLMax, curRMax) - height[i];
            }          
        }
        return sum;
    }
};