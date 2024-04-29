#
# @lc app=leetcode.cn id=73 lang=python
#
# [73] 矩阵置零
#

# @lc code=start
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # 使用「原地」算法
        if not matrix or not matrix[0]:
            return
        rows, cols = len(matrix), len(matrix[0])
        row_to_0 = False
        col_to_0 = False

        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    if i == 0:
                        row_to_0 = True
                    if j == 0:
                        col_to_0 = True
                    matrix[i][0] = 0
                    matrix[0][j] = 0
               
        for i in range(1, rows):
            for j in range(1, cols):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # 选用第0行为标志位 那么第0行就需要在最后处理
        # 列同理
        if (row_to_0):
            for j in range(cols):
                matrix[0][j] = 0
                
        if (col_to_0):
            for i in range (rows):
                matrix[i][0] = 0
                    
        # for row in matrix:
        #     print(row)
# @lc code=end

