/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int>letterMap;
        vector<int> res;
        int j = 0;
        for (char ch : s) {
            letterMap[ch] = j;
            j++;
        }
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, letterMap[s[i]]);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

