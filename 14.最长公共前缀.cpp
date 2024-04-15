/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = strs[0];
        int ansNum = -1;
        for (int i = 0; i < strs.size(); i++){       // 几个字符串
            ansNum = -1;
            int minLen = min(ans.length(), strs[i].length()); 
            for (int j = 0; j < minLen; j++){       // 判断前缀
                if (strs[i][j] != ans[j]) break;
                ansNum = j;
            }
        }
        ans = ans.substr(0, ansNum+1);
        if (ansNum == -1){
                return "";
        }
        else{
                return ans;
        }
       
    }
};
// @lc code=end

