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

        // 快慢指针
        for (int fast = 0; fast < numSize; ++fast){
            if (nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end

