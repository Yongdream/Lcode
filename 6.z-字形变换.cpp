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
        int n = s.size();
        int k = 2 * numRows - 2;
        
        vector<string> a(numRows);
        for (int i = 0; i < n; i++)
        {
            a[min(k - i % k, i % k)] += s[i];
        }
        return accumulate(a.begin(), a.end(), string(""));
    }

};
// @lc code=end

