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

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int direction = 0;  // 方向 注意后面代码 方向如何选择

        vector<int> res;

        while (top <= bottom && left <= right) {
            // 向右
            if (direction == 0)
            {
                for (int i = left; i <= right; ++i) {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            // 向下
            else if (direction == 1) {
                for (int i = top; i <= bottom; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            // 向左
            else if (direction == 2)
            {
                for (int i = right; i >= left ; --i)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // 向上
            else
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction + 1) % 4; // 选择模式
        }
        return res;
    }
};
// @lc code=end

