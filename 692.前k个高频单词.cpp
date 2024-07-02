/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    class cmp{
    public:
        bool operator()(const pair<string, int>& a, const pair<string, int>& b){
            if (a.second == b.second) {
                return a.first > b.first;   // 字典顺序
            }
            return a.second < b.second;     // 基于频率的最大堆
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map; // 存储高频单词的出现频率
        for (int i = 0; i < words.size(); ++i)
        {
            map[words[i]]++;
        }

        // 维护频率k的单词
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> min_heap; 
        for (auto entry : map)
        {
            min_heap.push(entry);
        }

        vector<string> res;
        // 前 k 个出现次数最多的单词 (区别与 频率前 k 高的元素)
        for (int i = 0; i < k; ++i)
        {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return res;        
    }
};
// @lc code=end

