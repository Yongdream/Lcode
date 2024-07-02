/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;    // 小顶堆
        for (int num : nums)
        {
            if (minHeap.size() < k) minHeap.push(num);
            else if (num > minHeap.top()){
                minHeap.pop();
                minHeap.push(num);
            }
        }
        return minHeap.top();
        
    }
};
// @lc code=end

