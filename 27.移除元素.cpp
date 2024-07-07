/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numSize = nums.size();
        int slow = 0;
        for (int i = 0; i < numSize; ++i)   // i就是快指针
        {
            if (nums[i] != val){
                nums[slow] = nums[i];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

