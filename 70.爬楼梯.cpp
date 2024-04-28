/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        if (n > 1) {
            dp[2] = 2;
            for (int i = 3; i <= n; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[n];
    }
};
// @lc code=end

