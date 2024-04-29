/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();
        int countM = rows * cols;
        int count = 0;

        int left = 0, right = cols - 1, up = 0, down = rows - 1;

        int i = 0;
        int j = 0;

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int direction = 0;
        vector<int> res;

        //while (count <= countM) {
        //    
        //}
        while (count <= countM)
        {
            while (j < right) {
                res.push_back(matrix[i][j]);
                j++;
                count++;
            }
            right--;
            while (i < down) {
                res.push_back(matrix[i][j]);
                i++;
                count++;
            }
            down--;
            while (j > left) {
                res.push_back(matrix[i][j]);
                j--;
                count++;
            }
            left++;
            while (i > up + 1) {
                res.push_back(matrix[i][j]);
                i--;
                count++;
            }
            up++;
        }

        return res;
    }
};
// @lc code=end

