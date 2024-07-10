/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int sizeStr = s.size();
        int i = sizeStr - 1, j = 0;
        bool strSeek = false;
        string res;

        while (i > 0 && s[i] == ' ') --i;       // 去尾空格
        while (j < sizeStr && s[j] == ' ') ++j; // 去头空格
        int strEnd = i; // 动态字符边界
        int strSta = j;

        while (i >= j)
        {   
            // cout << i << endl;
            if (s[i] == ' ' && (i == 0 || s[i-1] != ' ')) strEnd = i - 1;
            if ((s[i] != ' ' && (i == 0 || s[i-1] == ' ')) || (i == j)) {
                strSta = i;
                strSeek = true;
            }
            if (strSeek) {
                // cout << s.substr(strSta, strEnd - strSta + 1) << endl;
                res += s.substr(strSta, strEnd - strSta + 1);
                res += (i == j ?  "" : " ");
                strSeek = false;
            }
            --i;
        }
        return res;
    }
};
// @lc code=end

