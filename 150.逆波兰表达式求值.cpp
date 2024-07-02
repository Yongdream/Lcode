/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 后缀表达式
        // 遇见数字 加入栈
        // 遇到操作符 计算栈内数字
        stack<long long> st;
        long long res;

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                // 所以符号没有入栈 栈维护的是待计算数字
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num1 + num2);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num1 * num2);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
        res = st.top();
        st.pop();
        return res;               
    }
};
// @lc code=end

