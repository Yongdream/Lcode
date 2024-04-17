/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return "";
    }

    // 找出数组中最短的字符串
    size_t min_length = std::min_element(strs.begin(), strs.end(),
                                       [](const std::string& a, const std::string& b) {
                                           return a.size() < b.size();
                                       })->size();

    // 初始化最长公共前缀为空字符串
    std::string lcp;

    // 遍历最短字符串的每个字符
    for (size_t i = 0; i < min_length; ++i) {
        char current_char = strs[0][i];

        // 检查所有字符串的当前位置字符是否相同
        bool all_same = true;
        for (const auto& s : strs) {
            if (s[i] != current_char) {
                all_same = false;
                break;
            }
        }

        // 如果相同，将其添加到最长公共前缀中
        if (all_same) {
            lcp += current_char;
        } else {
            // 如果不同，跳出循环，返回当前的最长公共前缀
            break;
        }
    }

    return lcp;
}
};
// @lc code=end

