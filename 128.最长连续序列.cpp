/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for (const int& num:numSet){
            
            if (numSet.count(num - 1) == 0) {
                int curr_len = 1;
                // 检查连续序列的长度
                while (numSet.count(num + curr_len)) {
                    curr_len++;
            }
            
            // int prev_len = numSet.count(num - 1) ? numSet[num - 1] : 0;
            // // lengths.count(num - 1) 检查 unordered_map 中是否存在键 num - 1
            // // int next_len = lengths.count(num + 1) ? lengths[num + 1] : 0;
            // // cout << num << '\n' << prev_len << ' ' << next_len << endl;

            // int curr_len = prev_len + 1;
            // lengths[num] = curr_len;
            
            res = max(res, curr_len);
            // cout << curr_len << ' ' << res <<endl;

        }
        }
        return res;
    }
};
// @lc code=end

