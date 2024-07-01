/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    string path;
    vector<string> res;

    unordered_map<int, char> charMap{
        {0, '('},
        {1, ')'}
    };

    void backtrack(int n, int startIndex, int endIndex, string& path, vector<string>& res){
        if (endIndex == n){
            res.push_back(path);
            return;
        }

        if (startIndex < n) {
            path.push_back(charMap[0]);
            backtrack(n, startIndex + 1, endIndex, path, res);
            path.pop_back();
        }

        if (endIndex < startIndex) {
            path.push_back(charMap[1]);
            backtrack(n, startIndex, endIndex + 1, path, res);
            path.pop_back();
        }      
    }

    vector<string> generateParenthesis(int n) {
        path.clear();
        res.clear();
        backtrack(n, 0, 0, path, res);
        return res;
    }
};
// @lc code=end

