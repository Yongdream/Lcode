/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lemNums = nums.size();
        vector<int> ans(lemNums, 1);

        for (int i = 1; i < lemNums; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
            // ans[i - 1]保留了全部前向连乘结果
        }
        
        int suffix = 1;// 后缀suffix保留了全部后向连乘结果
        for (int i = lemNums - 2; i >= 0; --i) {
            suffix = suffix * nums[i + 1];
            ans[i] = ans[i] * suffix;
        }

        return ans;
    }
};
// @lc code=end

