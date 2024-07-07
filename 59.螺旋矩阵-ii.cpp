/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int direction = 0;  // 方向 注意后面代码 方向如何选择
        int num = 0;

        while (top <= bottom && left <= right) {
            // 向右
            if (direction == 0){
                for (int i = left; i <= right; ++i) {
                    res[top][i] = ++num;
                }
                top++;
            }
            // 向下
            else if (direction == 1) {
                for (int i = top; i <= bottom; i++)
                {
                    res[i][right] = ++num;   
                }
                right--;
            }
            // 向左
            else if (direction == 2) {
                for (int i = right; i >= left ; --i)
                {
                    res[bottom][i] = ++num;     
                }
                bottom--;
            }
            // 向上
            else{
                for (int i = bottom; i >= top; i--)
                {
                    res[i][left] = ++num;
                }
                left++;
            }
            direction = (direction + 1) % 4; // 选择模式
        }
        return res;
    }
};
// @lc code=end

