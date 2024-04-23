/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> win; // 记录的是窗口中元素的索引 而不是实际元素值

        if (k > nums.size()) return res;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!win.empty() && win.front() == i - k){
                win.pop_front();
            }

            // 一种降序的思想
            // 保证首位一定为最大的值
            while (!win.empty() && nums[i] >= nums[win.back()]){
                win.pop_back();
            }
            
            win.push_back(i);   // 记录索引
            // cout << nums[win.front()] << endl;
            
            if (i >= k-1){
                res.push_back(nums[win.front()]);
                // res.push_back(win[win.begin()]);
            }
        }

        return res;
    }
};
// @lc code=end

