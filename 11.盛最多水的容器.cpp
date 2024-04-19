/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size() - 1;
         while (left < right)
         {
            int w = right -left;
            int area = w * min(height[left], height[right]);
            maxarea = max(maxarea, area);

            if (height[right] < height[left])
            {
                right--;
            }
            else left++;
         }
         
         return maxarea;
    }
};
// @lc code=end

