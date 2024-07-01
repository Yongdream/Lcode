/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking (vector<int>& nums, int startIndex){
        res.push_back(path);    // 3
        // 收集子集，要放在终止添加的上面，否则会漏掉自己

        if (startIndex >= nums.size()) {
            return;
        }
        // [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
        for (int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);    // 1
            backtracking(nums, i + 1);  // 2
            path.pop_back();    // 4
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;        
    }
};
// @lc code=end

