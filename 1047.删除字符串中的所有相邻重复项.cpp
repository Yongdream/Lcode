/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char sub : s)
        {
            if (st.empty() || sub != st.top())
            {
                st.push(sub);
            }
            else
            {
                st.pop();
            }
        }

        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());    // 字符需要反转
        return res;
        // 相邻的做匹配 做消除
    }
};
// @lc code=end

