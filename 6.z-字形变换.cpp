/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        
        vector<vector<char>> rows(numRows, vector<char>(s.length(), '\0'));
        vector<int> positions(numRows, 0);

        int jiegou = (s.length()) / (2*numRows-2);
        std::cout << "jiegou: " << jiegou << std::endl;
        

        for(char ch:s){
            int currentRow = positions.back() % numRows;
            int index = positions.back()++;
            rows[currentRow][index] = ch;

            if (currentRow == 0 || currentRow == numRows - 1) {
                positions.pop_back();
                positions.insert(positions.begin(), positions.back() * -1);
            }
        }
        
        std::string result;
        for (const auto& row : rows) {
            for (const auto& ch : row) {
                if (ch != '\0') { // 只添加非空字符
                    result += ch;
                }
            }
        }
        return result;
    }

};
// @lc code=end

