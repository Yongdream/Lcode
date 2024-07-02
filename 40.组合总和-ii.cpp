/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used){
        if (sum > target) return;
        if (sum == target) {
            res.push_back(path);
            return;
        }
            
        for (int i = startIndex; i < candidates.size(); i++)
        {
            // candidates[i] == candidates[i - 1] 并且 used[i - 1] == false
            // i > 0 保证不会越界
            // 说明：前一个树枝，使用了candidates[i - 1]    
            // 理解used是对nums使用的跟踪 used[i - 1] 没有被使用 就不要被使用了

            // 如果 used[i - 1] 是 true，
            // 这意味着在当前的递归路径上，索引 i - 1 处的数字已经被考虑过并使用过了
            // 意味着在当前的组合中包含了这个数字，并且我们正在尝试找到其他可能的组合。
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtrack(candidates, target, sum, i+1, used);  // i 不可以重复 故指定 startIndex = i+1
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }      
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        // 去重处理 
        // 47.全排列II 、90.子集II
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, used);
        return res; 
    }
};
// @lc code=end

