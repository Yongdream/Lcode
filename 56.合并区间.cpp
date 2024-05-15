/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
            });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (merged.back()[1] >= intervals[i][0]) {
                merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
            }
            else merged.push_back(intervals[i]);
        }
        return merged;
    }
};
// @lc code=end

