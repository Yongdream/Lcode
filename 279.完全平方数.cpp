/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                // i - j * j 保证了最后缺少一个完全平方数
                // 因此需要+1
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];


        //int nSqrt = (int)(sqrt(i));
        //for (int i = 1; i <= nSqrt; ++i) {
        //    float remain = n - (nSqrt) * (nSqrt);
        //    int remainInt = (int)(n - (nSqrt) * (nSqrt));
        //    if (sqrt(remain * remain) == sqrt(remainInt * remainInt)) {
        //        // 剩余的是一个完全平方数
        //        ans++;
        //    }
        //    
        //}
    }
};
// @lc code=end

