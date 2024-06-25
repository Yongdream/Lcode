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

    queue<pair<int, int>> que_; // bfs一般会和队列相搭嘎
    int row_;
    int col_;
    int res = 0;
     
    void bfs(int x, int y, vector<vector<char>>& grid){
        /**
         * 1. 源点进队
         * 2. 队列不为空时 拿出队首元素cur
         * 3. 对队首元素进行扩展「遍历cur的邻接表」           
        */

        que_.push({x, y});  // 1. 源点进队
        grid[x][y] = 0;

        while (!que_.empty())   // 2. 队列不为空时 拿出队首元素cur
        {
            auto p = que_.front();
            que_.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nextx = p.first + dx_[i];   // 辐射开来
                int nexty = p.second + dy_[i];
                if (0 <= nextx && nextx < row_ && 
                    0 <= nexty && nexty < col_ && grid[nextx][nexty] == '1')
                {
                    grid[nextx][nexty] = '0';
                    que_.push({nextx, nexty});  // 3. 对队首元素进行扩展「遍历cur的邻接表」
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        row_ = grid.size();
        col_ = grid[0].size();

        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (grid[i][j] == '1')
                {
                    bfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;            
    } 
};
// @lc code=end

