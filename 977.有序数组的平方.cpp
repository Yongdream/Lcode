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
        int edge = numSize - 1;
        vector<int> res(numSize, 0);

        int left = 0;
        int right = edge;
        while (left <= right)
        {
            if (nums[right] * nums[right] > nums[left] * nums[left]){
                res[edge--] = nums[right] * nums[right];
                right--;
            }
            else{
                res[edge--] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

