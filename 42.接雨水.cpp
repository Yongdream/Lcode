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
        int n = height.size();
        int l = 0;
        int r = l + 2;
        int areaSum = 0;

        while (r < n-1)
        {
            int area = 0;
            if (height[l+1] < height[l] && height[r] > height[l+1] )
            {
                area = min(height[l], height[r]) - height[l+1];
                cout << area << endl;
                areaSum += area;
            }
            l++;
            r++;
        }
        return areaSum;
    }
};
// @lc code=end

