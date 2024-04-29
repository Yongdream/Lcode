/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;

        int rows = matrix.size();   // 行
        int cols = matrix[0].size();// 列

        int left = 0;
        int right = rows * cols - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midNum = matrix[mid / cols][mid % cols];

            if (midNum == target) {
                return true;
            }
            else if (midNum < target) {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;

    }
};
// @lc code=end

