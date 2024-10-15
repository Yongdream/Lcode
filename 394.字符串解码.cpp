/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> stkStr;       // 维护括号内容
        stack<int> stkNum;          // 维护重复次数

        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            // 出现数字 找到重复字符串
            if (c >= '0' && c <='9'){
                int num = 0;
                while (c >= '0' && c <='9')
                {
                    num = num * 10 + (c - '0'); // 构建数字
                    c = s[++i];
                }
                --i;                // 回退到非数字字符，因为循环会多移动一位
                stkNum.push(num);   // 将数字压入栈
            }
            else if (c == '['){
                stkStr.push(res);
                res = "";
            }
            else if (c == ']'){
                string temp = res;
                res = stkStr.top();
                stkStr.pop();
                int repeatTimes = stkNum.top();
                stkNum.pop();
                while (repeatTimes-- > 0) {
                    res += temp;
                }
            }
            else{
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end

