/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
class Solution{
	public:
			vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> m;
			vector<int> ans;
			for (int i = 0; i < nums.size(); i++)
			{
				auto it = m.find(target-nums[i]);
				if (it != m.end())
				{
					ans.push_back(it->second);
					ans.push_back(i);
					break;
				}
				else{
					m.insert({nums[i], i});
				}
				
			}
			return ans;
    }   
};

// @lc code=end

