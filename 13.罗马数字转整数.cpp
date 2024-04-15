/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanMap ={
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        int preVal = 0;

        for (size_t i = 0; i < s.length(); i++){
            char ch = s[i];
            int curVal = romanMap[ch];
            if (curVal > preVal && i > 0) {
                result += curVal - 2 * preVal;
                // 注意这里*2的含义
                // 在上一次遍历时候 并没有出现小大的关系 所以curVal被加上了
            }
            else{
                result += curVal;
            }
        preVal = curVal;
        }
        return result;
    }
};
// @lc code=end

