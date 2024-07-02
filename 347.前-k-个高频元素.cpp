/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    // 小顶堆
    // 如何初始化一个可以存储哈希映射的最小堆
    class cmp{
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second; // 大顶堆
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 「大顶堆 小顶堆」 适合求前k个高频、低频问题
        // 大顶堆 父节点一定大于子节点
        // 小顶堆 pop() root节点 最小的值

        // Step 1: Frequency map
        unordered_map<int, int> map;    // 维护元素出现的频率
        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]]++;
        }

        // Step 2: Min-heap (size heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;

        for (auto entry : map)
        {
            min_heap.push(entry);
            // if (min_heap.size() > k) {
            //     min_heap.pop();
            // }
        }

        // Step 3: Collecting results
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            // 692.前K个高频单词
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return res;
    }
};
// @lc code=end

