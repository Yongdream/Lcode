/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res; 
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        for (int i = 0; i < n-2; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重
            
            int left = i + 1, right = n - 1;    // 初始化左右指针
            while (right > left){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    // res.push_back({nums[i], nums[left], nums[right]});
                    
                    // 去重
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
                else if (sum < 0) ++left;
                else --right;
            }

        }
        return res;
    }
};
// @lc code=end

