/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 亦或思想
        // 交换律：a ^ b ^ c <=> a ^ c ^ b
        // 任何数于0异或为任何数 0 ^ n = > n
        // 相同的数异或为0 : n ^ n = > 0
        for (int i = 1; i < nums.size(); i++)
        {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};
// @lc code=end

