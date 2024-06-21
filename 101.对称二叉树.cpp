/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
        // 是否对称就是是否可以翻转
    }
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        // 节点存在判断
        if (left == nullptr && right != nullptr) return false;
        if (left != nullptr && right == nullptr) return false;
        if (left == nullptr && right == nullptr) return true;

        // 节点值判断
        if (left->val != right->val) return false;

        bool outside = isMirror(left->left, right->right);
        bool inside = isMirror(left->right, right->left);
        bool res = (outside && inside);

        return res;

    }
};
// @lc code=end

