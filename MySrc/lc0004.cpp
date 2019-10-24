//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 特殊情况
        if (nums1.size() == 0) {
            if(nums2.size() == 1) {
                return nums2[0];
            }
            return ((float)nums2[(nums2.size()-1)/2] + (float)nums2[nums2.size()/2])/2;
        } else if(nums2.size() == 0) {
            if(nums1.size() == 1) {
                return nums1[0];
            }
            return ((float)nums1[(nums1.size()-1)/2] + (float)nums1[nums1.size()/2])/2;
        }
        // 分治法
        while (nums1.size() > 2 && nums2.size() > 2) {
            int k1 = nums1.size()/2;
            float num1 = nums1[k1]; 
            if (nums1.size() % 2 == 0) {
                k1 = nums1.size()/2 - 1;
                num1 = ((float)nums1[k1] + nums1[k1+1])/2;
            }
            int k2 = nums2.size()/2;
            float num2 = nums2[k2]; 
            if (nums2.size() % 2 == 0) {
                k2 = nums2.size()/2 - 1;
                num2 = ((float)nums2[k2] + nums2[k2+1])/2;
            }
            if (num1 == num2) {
                return num1;
            } else if (num1 < num2) {
                int offset = min(k1, k2);
                RemoveLeft(nums1, offset);
                RemoveRight(nums2, offset);   
            } else {
                int offset = min(k2, k1);
                RemoveLeft(nums2, offset);
                RemoveRight(nums1, offset);
            }
        }
        // 结果处理
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        return ((float)nums1[(nums1.size()-1)/2] + (float)nums1[nums1.size()/2])/2;
    }
    
private:
    void RemoveLeft(vector<int>& nums, int offset)
    {
        while (offset > 0 && nums.size() > 0) {            
            nums.erase(nums.begin());
            offset--;
        }
    }
    void RemoveRight(vector<int>& nums, int offset)
    {
        while (offset > 0 && nums.size() > 0) {
            nums.pop_back();
            offset--;
        }
    }
};