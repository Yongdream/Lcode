/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int tempSum = 0;

        for (int num : nums){
            tempSum += num;
            if (map.find(tempSum-k) != map.end()){
                res += map[tempSum-k];
            }
            map[tempSum]++;
        }
        return res;
    }
};
// @lc code=end

