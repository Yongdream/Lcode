/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        int record[26] = {0};
        for (int i = 0; i < magazine.size(); ++i)
        {
            record[magazine[i]-'a'] ++;
        }
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            record[ransomNote[i]-'a']--;
            if (record[ransomNote[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

