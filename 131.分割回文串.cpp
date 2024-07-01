/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    void backtrack (const string& s, int startIndex) {
        if (startIndex >= s.size()){
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);  // pending substr的总结
                path.push_back(str);
            }
            else continue;
            backtrack (s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        backtrack(s, 0);
        return res; 
    }
};
// @lc code=end

