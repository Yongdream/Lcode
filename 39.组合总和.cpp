/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int sum, int startIndex){
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, sum, i);  // 数字可用多次 仍从i开始
            sum -= candidates[i];
            path.pop_back();
        }      
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtrack(candidates, target, 0, 0);
        return res;        
    }
};
// @lc code=end

