/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> sMap;
        int right = 0 ;
        int left = 0;
        int vaild = 0;
        // int winMinLen = s.size() + 1;
        int winMinLen = INT_MAX;    // int类型的最大值
        int start = 0;
        // if (t.size() > s.size()) return "";

        for(char c : t){
            tMap[c]++;
        }

        while (right < s.size())
        {
            char d = s[right];
            right++;
            if(tMap.count(d)){
                sMap[d]++;
                if (sMap[d] == tMap[d]) vaild++;
            }

            while (vaild == tMap.size())    // 思考为什么是tMap而不是t
            // 当t中存在重复字母时出现错误 例如t = "aa" 
            // vaild会在sMap和tMap匹配时才生效
            {
                if (right - left < winMinLen){
                    winMinLen = right - left;
                    start = left;
                }
                char e = s[left];
                left++;
                if(tMap.count(e)){
                    if (sMap[e] == tMap[e]) vaild--;
                    sMap[e]--;
                } 
            }
        }
        return winMinLen == INT_MAX ? "" :  s.substr(start, winMinLen);

    }
};
// @lc code=end

