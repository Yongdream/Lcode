/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void reverse(vector<int>::iterator first, vector<int>::iterator last) {
        while ((first != last) && (first != --last)) {
            swap(*first, *last);
            ++first;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

