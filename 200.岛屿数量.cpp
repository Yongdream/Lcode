/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
private:
    int dx_[4] = {0, 0, -1, 1};  // 四个方向
    int dy_[4] = {1, -1, 0, 0};

    int row;
    int col;

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        if (visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = true;

        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dx_[i];
            int nexty = y + dy_[i];
            if (nextx < 0 || nextx >= grid.size() ||
                nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
            dfs(grid, visited, nextx, nexty);   // 递归 
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        // 初始化待访问的二维网格
        vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
        
        int result = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;        
    }
};
// @lc code=end

