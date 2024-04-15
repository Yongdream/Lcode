/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        std::string str = std::to_string(x);
        int size = str.length();

        for(int i = 0;i < size/2;i++){
            if(str[i]!=str[size-i-1]) return false;
        }
        return true;
    }
};
// @lc code=end

