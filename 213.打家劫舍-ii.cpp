/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 3) {
            return *max_element(nums.begin(), nums.end());
        }
        
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        dp1[1] = nums[1];
        dp1[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) {
            dp1[i] = max(dp1[i-1], nums[i] + dp1[i - 2]);
        }

        dp2[0] = nums[0];
        dp2[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n - 1; ++i) {
            dp2[i] = max(dp2[i - 1], nums[i] + dp2[i - 2]);
        }
        
        return max(dp1[n-1],dp2[n-2]);
    }
};
// @lc code=end

