/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int res = nums[0];
        int temp = nums[0];
        for (int i=1; i < nums.size(); ++i){
            temp = max(nums[i], temp+nums[i]);
            res = max(res, temp);
        }
        return res;
    }
};
// @lc code=end

