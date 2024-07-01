/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    int dx_[4] = {0, 0, -1, 1};
    int dy_[4] = {1, -1, 0, 0};

    int row;
    int col;

    bool  dfs(vector<vector<char>>& board, string& word, int k, int x, int y){
        /**
         * k 代表查到第几个字符 自然想到作为终结条件
        */
        if (k == word.size()) return true;       
        if (x < 0 || x >= row || 
            y < 0 || y >= col || 
            board[x][y] != word[k]) return false;

        char temp = board[x][y];
        board[x][y] = '*';

        for (int i = 0; i < 4; ++i)
        {
            int nextx = x + dx_[i];
            int nexty = y + dy_[i];
            if (dfs(board, word, k + 1, nextx, nexty)) return true; // 被访问过的要被处理
        }
        board[x][y] = temp; // 注意这种回溯 区别「visited」
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) return true;
            }
        }
        return false; 
    }
};
// @lc code=end

