/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (auto n1 : nums1)
        {
            for (auto n2 : nums2){
                mp[n1 + n2]++;
            }
        }
        int res = 0;
        for (auto n3 : nums3){
            for (auto n4 : nums4)
            {
                if (mp.find(0 - (n3 + n4)) != mp.end()) res += mp[0 - (n3 + n4)];
            }  
        }
        return res;
    }
};
// @lc code=end

