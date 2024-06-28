/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
private:
    int row_;
    int col_;
    int res_ = -1;

    queue<pair<int, int>> que_;
    
    int dx_ = {0, 0, 1, -1};
    int dy_ = {1, -1, 0, 0};

    int bfs(vector<vector<int>>& grid, int x, int y){
        que_.push({x, y});  // 1. 源点进队
        grid[x][y] = 0;

        while (!que_.empty())
        {

        }

    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        row_ = grid.size();
        col_ = grid[0].size();

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 2)
                {
                    dfs(grid, x, y);
                }
            }
        }

    }
};
// @lc code=end

