// https://leetcode-cn.com/problems/container-with-most-water/


// 双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxW = height.size() - 1;
        int maxArea = 0;
        // 左指针向右移
        for(int i = 0; i < height.size(); i++) {
            int tmpArea = (maxW - i) * min(height[i], height[maxW]);
            maxArea = max(maxArea, tmpArea);
            // 右指针向左移
            for(int j = height.size() - 2; j > i; j--) {
                if(height[j] <= height[maxW]) {
                    continue;
                }
                int tmpArea = (j - i) * min(height[i],  height[j]);
                maxArea = max(maxArea, tmpArea);
            }
        }
        return maxArea;
    }
};
