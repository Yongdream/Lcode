/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0; 
        int areaSum = 0;
        int lMax = 0, rMax = 0;
        int l = 0, r = height.size() - 1;

        while (l <= r)
        {
            if(lMax > rMax){
                rMax = max(rMax, height[r]);
                areaSum += rMax - height[r--];
            }
            else{
                lMax = max(lMax, height[l]);
                areaSum += lMax - height[l++];
            }
        }
        return areaSum;
    }
};
// @lc code=end

