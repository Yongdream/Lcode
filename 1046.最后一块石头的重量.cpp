/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;    // 最大堆
        for (auto stone : stones) que.push(stone);
        
        while (que.size() > 1)
        {
            int x = que.top();
            que.pop();
            int y = que.top();
            que.pop();
            que.push(x - y);
        }
        return que.empty()? 0 : que.top();        
    }
};
// @lc code=end

