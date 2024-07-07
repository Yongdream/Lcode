/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = __INT_MAX__;
        int sum =0;
        int left = 0;
        int len = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = right - left + 1;
                res = min(res, len);
                sum -= nums[left];
                left++;
            }
        }

        return res == __INT_MAX__? 0 : res;
    }
};
// @lc code=end

