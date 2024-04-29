/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n - 1;   // 右顶开始查找 
        // 左顶->右底 是递增的
        
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;    // 下移
            else j--;   // 左移
        }

        return false;


    }
};
// @lc code=end

