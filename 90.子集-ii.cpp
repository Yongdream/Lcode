/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking (vector<int>& nums, int startIndex, vector<bool>& used){
        res.push_back(path);    // 3
        // 收集子集，要放在终止添加的上面，否则会漏掉自己

        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);    // 1
            used[i] = true;
            backtracking(nums, i + 1, used);  // 2
            used[i] = false;
            path.pop_back();    // 4
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        // 去重处理 
        // 47.全排列II 、40.组合总和II
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return res;  
    }
};
// @lc code=end

