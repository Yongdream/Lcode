/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        unordered_map<int, int> countMap;
        vector<int> res;

        for (int num : nums) {
            countMap[num]++;
        }

        vector<int> candidates;
        int candidateCount = 0;

        for (const auto& kv : countMap)
        {
            if (kv.second > k) {
                candidates.push_back(kv.first);
                candidateCount++;
            }
        }

        for (int candidate : candidates)
        {
            if (countMap[candidate] > k) {
                res.push_back(candidate);
            }
        }

        return res;

    }
};
// @lc code=end

