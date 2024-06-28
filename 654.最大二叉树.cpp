/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if (left > right) return nullptr;
        int maxIndex = left;
        for (int i = left + 1; i < right; ++i)
        {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxIndex);
        root->right = traversal(nums, maxIndex + 1, right);

        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 构造二叉树 一定选择「前序遍历」
        return traversal(nums, 0, nums.size());

        // TreeNode* node = new TreeNode(0);
        // if (nums.size() == 1)
        // {
        //     node->val = nums[0];
        //     return node;
        // }

        // // 最大值及其下标index
        // int maxVal = 0;
        // int maxValIndex = 0;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if (nums[i] > maxVal)
        //     {
        //         maxVal = nums[i];
        //         maxValIndex = i;
        //     }
        // }

        // node->val = maxVal; // 前
        // // 左 保证存在子树
        // if (maxValIndex > 0) 
        // {
        //     vector<int> newVec(nums.begin(), nums.begin() + maxValIndex);
        //     node->left = constructMaximumBinaryTree(newVec);
        // }
        // if (maxValIndex < (nums.size() - 1))
        // {
        //     vector<int> newVec(nums.begin() + maxValIndex + 1, nums.end());
        //     node->right = constructMaximumBinaryTree(newVec);   
        // }
        // return node;
    }
};
// @lc code=end

