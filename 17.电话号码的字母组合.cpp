/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    unordered_map<char, string> phoneMap{
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> res;
    string path;
    
public:
    void backtracking(const string& digits, int index){
        if (index == digits.size()){
            res.push_back(path);
            return;
        }

        // 取出字母集
        char digit = digits[index];
        string letters = phoneMap[digit];   
        
        // 回溯
        for (int i = 0; i < letters.size(); ++i)
        {
            path.push_back(letters[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        path.clear();
        res.clear();
        if (digits.size() == 0) return res;
        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end

