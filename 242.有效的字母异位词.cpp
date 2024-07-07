/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> charCount;

        for (char c : s) charCount[c]++;

        // 检查字符串t中的每个字符是否与s中的字符出现次数相同
        for (char c : t) {
            // 如果字符不在哈希表中或计数为0，则t不是s的字母异位词
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false;
            }
            // 减少字符的计数
            charCount[c]--;
        }

        for (auto& pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

