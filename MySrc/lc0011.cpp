// https://leetcode-cn.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxW = size - 1;
        int maxA = 0, maxTmp = 0;
        
        for(int i = 0; i < size; i++){
            maxA = max(maxA, (maxW - i) * min(height[i], height[maxW]));

            for(int j = size - 2; j > i; j--){
                if(height[j] < height[maxW])
                    continue;
                else{
                    int maxTmp = (j - i) * min(height[i], height[j]);
                    maxA = max(maxA, maxTmp);
                }                    
            }
        }
        return maxA;
    }
};