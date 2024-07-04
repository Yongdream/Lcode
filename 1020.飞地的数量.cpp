/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
private:
    int dx_[4] = {0, 0, -1, 1};  // 四个方向
    int dy_[4] = {1, -1, 0, 0};

    int row_;
    int col_;
    int res = 0;

    void dfs (vector<vector<int>>& grid, int i, int j){
        grid[x][y] = 0;
        res++;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row_ = grid.size();
        int col_ = grid[0].size();
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (grid[i][j] == 1) dfs(grid, i, j);
            }
        }
    }
};
// @lc code=end

