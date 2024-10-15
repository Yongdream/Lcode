/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int edge = 0;
        int len = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            while (sum >= target)
            {
                len = i - edge + 1;
                res = min(res, len);
                sum -= nums[edge];
                edge++;
            }
        }

        return res == INT_MAX? 0 : res;
    }
};
// @lc code=end

