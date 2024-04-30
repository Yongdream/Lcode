/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;

        int step = 0;
        int maxStep = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= maxStep) {
                maxStep = max(maxStep, i + nums[i]);
                if (maxStep >= nums.size() - 1) return true;
            }
        }
        return false;
    }
};
// @lc code=end

