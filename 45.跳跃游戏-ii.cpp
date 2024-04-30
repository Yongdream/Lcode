/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int stepCount = 0;
        int maxReach = 0;
        int reach = 0;  // 覆盖范围右边缘

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            maxReach = max(maxReach, nums[i] + i);  // 记录最远距离
            if (i == reach) {   // 覆盖范围 不关心具体怎么跳跃的
                stepCount++;
                //cout << reach << endl;
                reach = maxReach;   // 更新原本范围内的最大到达距离
            }
        }
        return stepCount;
    }
};
// @lc code=end

