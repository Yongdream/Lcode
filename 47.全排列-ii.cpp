/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void backtrack (vector<int>& nums, vector<bool>& used){
        if (path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            
            if (used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, used);
                path.pop_back();    
                used[i] = false;    // 回溯过程
            }           
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 去重处理 
        // 40.组合总和II 、90.子集II
        // 强调：去重一定要对元素进行排序，方便通过相邻的节点来判断是否重复使用了
        res.clear();
        path.clear();  
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};
// @lc code=end

