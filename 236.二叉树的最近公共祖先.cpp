/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        if (root == q || root == p) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);    // 回溯左边找到的根节点
        TreeNode* right = lowestCommonAncestor(root->right, p, q);  // 回溯右边找到的根节点

        if (left && !right) return left;    // 右边NULL 返回左边
        else if (right && !left) return right;
        else if (left && right) return root;    // 左右都找到 返回根节点
        else return NULL;
    }
};
// @lc code=end

