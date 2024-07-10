/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i+=(2*k))
        /**
         * 隔 2k 个字符
         * 是否甚于k个字符及以上
        */
        {
            if (s.size() - i > k){
                reverse(s.begin()+i, s.begin()+i+k);
            }
            else{
                reverse(s.begin()+i, s.end());
            }
        }
        return s;
    }
};
// @lc code=end

