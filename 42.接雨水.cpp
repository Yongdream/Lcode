/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0; 
        int areaSum = 0;
        int lMax = 0, rMax = 0;
        int l = 0, r = height.size() - 1;

        while (l <= r)
        {
            if(lMax > rMax){        // 比较的意义在于"短板效应"
                                    // 定住最长的那一个柱子
                // 初始赋值注意指针移动
                // 影响while判断的条件
                rMax = max(rMax, height[r]);
                areaSum += rMax - height[r--];
                // 指针在max值时候会让加结果为0
            }
            // 没有初始值前这决定了一开始的移动
            else{
                lMax = max(lMax, height[l]);
                areaSum += lMax - height[l++];
            }
        }
        return areaSum;
    }
};
// @lc code=end

