/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 中位数一定为多数元素
        // 排序函数时间复杂度：O(nlogn) 故不适用

        // boyer-moore算法
        // 坏字符规则（Bad Character Rule）和 好后缀规则（Good Suffix Rule）
        int count = 0;
        int candidate = nums[0];
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
// @lc code=end

