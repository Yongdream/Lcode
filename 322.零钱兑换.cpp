/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        sort(coins.begin(), coins.end());
        //cout << coins[1] << endl;
        //int remain = amount;

        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                    //cout << dp[i] << endl;
                }
            }
        }
        if (dp[amount] == amount + 1) return -1;
        return dp[amount];
        

    }
};
// @lc code=end

