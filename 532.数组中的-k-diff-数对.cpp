/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        int lenNums = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < lenNums; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            // lower_bound 用于在 已排序的范围内 二分查找 第一个不小于给定值的元素的位置
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), k + nums[i]);
            if (it == nums.end())
                break;
            if (*it == k + nums[i])
                ++ans;
        }

        return ans;
    }
};
// @lc code=end

