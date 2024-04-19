/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;   // 以被排序后的string为key 以原string为value
        vector<vector<string>> res;

        for (const string& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            // cout <<  sortedStr << endl;
            mp[sortedStr].push_back(str);
            // cout <<  "str:" <<str << endl;
        }

        for(const auto& pair : mp){
            res.push_back(pair.second);
        }

        return res;

    }
};
// @lc code=end

