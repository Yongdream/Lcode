/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res; 
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        for (int i = 0; i < n-3; ++i)
        {
            for (int j = i+1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // 去重
                int left = j + 1, right = n - 1;    // 初始化左右指针
                while (right > left)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target){
                        cout << i << j << left << right << endl;
                        res.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                        // 去重
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                    else if (sum < target) ++left;
                    else --right;
                }    
            }
        }
        return res;       
    }
};
// @lc code=end
