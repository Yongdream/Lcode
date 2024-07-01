/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
private:
    int row_, col_;
    int res_ = -1;

    queue<pair<int, int>> que_;
    
    int dx_[4] = {0, 0, 1, -1};
    int dy_[4] = {1, -1, 0, 0};

    void bfs(vector<vector<int>>& grid){

        int freshCount = 0; // 统计新鲜橘子的数量

        // 寻找所有腐烂橘子并初始化队列
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                if (grid[i][j] == 2){
                    que_.push({i, j});      // 初始化腐烂橘子
                }
                else if (grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        // 没有新鲜橘子 就不会存在腐烂过程
        if (freshCount == 0) {
            res_ = 0;
            return;
        }

        int minutes = 1;
        while (!que_.empty())
        {
            int size = que_.size();
            for (int k = 0; k < size; ++k)
            {
                auto [x, y] = que_.front();
                que_.pop();
                for (int i = 0; i < 4; ++i) // 开始传染
                {
                    int newX = x + dx_[i];  //上下左右
                    int newY = y + dy_[i];

                    if (newX >= 0 && newX < row_ && // 边界
                        newY >= 0 && newY < col_ && 
                        grid[newX][newY] == 1   // 新鲜橘子
                        )   
                    {
                        grid[newX][newY] = 2;   // 将新鲜橘子变为腐烂
                        freshCount--;
                        que_.push({newX, newY});
                    }
                }
            }
            if (freshCount > 0) minutes++; // 如果还有新鲜橘子，增加时间
        }
        // 如果所有橘子都腐烂了，返回分钟数，否则返回-1
        res_ = freshCount == 0 ? minutes : -1;
    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        row_ = grid.size();
        col_ = grid[0].size();

        bfs(grid); // 执行BFS搜索
        return res_;
    }
};
// @lc code=end

