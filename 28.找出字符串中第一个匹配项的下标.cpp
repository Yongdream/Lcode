/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int neSize = needle.size(), haSize = haystack.size();
        if (neSize > haSize) return -1;

        int i = 0;
        int j = 0;
        while (i < haSize - neSize + 1)
        {
            /**寻找首字母相同 起始位*/
            while (i < haSize && haystack[i] != needle[j]) i++;
            if (i == haSize) return -1; // 没有首字母相等的

            /**同时向前匹配*/
            while (i < haSize && j < neSize && haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == neSize)  return i - j;   // 找到
            else {                                  // 未找到 需要回溯
                i -= j-1;
                j = 0;
            }
        }
        return -1;
    }
};
// @lc code=end

