/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (const string& str :strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(str);
        }

        for(const auto& pair : mp){
            res.push_back(pair.second);
        }

        return res;

    }
};
// @lc code=end

