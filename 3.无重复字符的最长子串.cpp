/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> charIndexMap;
        int left = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            char currChar = s[right];
            if (charIndexMap.find(currChar) != charIndexMap.end() &&
            charIndexMap[currChar] >= left) {
                left = charIndexMap[currChar] + 1;
            }
            
            charIndexMap[currChar] = right;
            // cout << right << endl;
            res = max(res, right - left + 1);
        }
        return res;
        

    }
};
// @lc code=end

