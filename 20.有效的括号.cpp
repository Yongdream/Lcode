/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else {
                if (stack.empty()) {
                    // 如果此时栈已经为空，说明没有对应的左括号
                    return false;
                }

                if ((c == ')' && stack.top() != '(') ||
                    (c == '}' && stack.top() != '{') ||
                    (c == ']' && stack.top() != '[')){
                        return false;
                    }
                stack.pop();  // 弹出栈顶的左括号  
            }
        }
        return stack.empty();
    }
};
// @lc code=end

