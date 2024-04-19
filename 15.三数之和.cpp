/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // for (const int& num : nums )
        // {
        //     cout << num << endl;
        // }
        
        int right = nums.size() - 1;
        int left = 0;
        vector<vector<int>> res;

        while (right > left)
        {
            for(int k = left + 1 ; k < right - 1; ++k)
            {
                long long sum = static_cast<long long>(nums[k]) + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back({nums[k], nums[left], nums[right]});
                    // 跳过相同的元素
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                }
                else if (sum < 0) ++left;
                else --right;
                
            }
        }
        return res;
    }
};
// @lc code=end

