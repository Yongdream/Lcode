/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int res_ = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return res_;
        traversal(root, targetSum);
        int temp_l = pathSum(root->left, targetSum);   // 递归 以每一个根节点为基础 也就不展示出回溯的过程
        int temp_r = pathSum(root->right, targetSum);  // 递归
        return res_;
    }

    void traversal(TreeNode* cur, long long count) {
        if (!cur) return;   // 对 count 变量使用了 long long 类型，以确保在大数情况下不会发生溢出

        count -= cur->val;
        if (count == 0) res_++;

        traversal(cur->left, count);
        traversal(cur->right, count);
        
    }
};
// @lc code=end

