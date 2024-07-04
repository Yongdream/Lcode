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

    void dfs (vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        res++;
        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dx_[i];
            int nexty = y + dy_[i];
            if (nextx < 0 || nextx >= row_ || nexty < 0 || nexty >= col_){
                continue;
            }
            if (grid[nextx][nexty] == 0) continue;
            dfs (grid, nextx, nexty);
        }
        return;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        row_ = grid.size();
        col_ = grid[0].size();
        // 从左侧边，和右侧边 向中间遍历
        for (int i = 0; i < row_; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);
            if (grid[i][col_ - 1] == 1) dfs(grid, i, col_ - 1);
        }
        // 从上边和下边 向中间遍历
        for (int j = 0; j < col_; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);
            if (grid[row_ - 1][j] == 1) dfs(grid, row_ - 1, j);
        }
        res = 0;
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (grid[i][j] == 1) dfs(grid, i, j);
            }
        }
        return res;
    }
};
// @lc code=end

