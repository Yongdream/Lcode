/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);    // 初始化为0 
        stack<int> st;

        st.push(0);
        for (int i = 1; i < temperatures.size(); ++i)
        {
            if (temperatures[i] > temperatures[st.top()]){
                // temperatures[st.top()] < temperatures[i]
                // [...75,71,69,72,76...] pop后仍要保证大小关系
                // 前面可以有低温的index 不能有高温的index
                while (!st.empty() && 
                        temperatures[st.top()] < temperatures[i])
                {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
            else{
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

