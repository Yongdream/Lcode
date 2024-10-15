/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> res(numSize, 0);
        int edge = numSize -1;
        int left = 0, right = edge;
        while(left <= right)
        {
            if (nums[left] * nums[left] > nums[right] * nums[right]){
                res[edge] = nums[left] * nums[left];
                edge--;
                left++;
            }
            else{
                res[edge] = nums[right] * nums[right];
                edge--;
                right--;
            }
        }
        return res;
    }
};
// @lc code=end

