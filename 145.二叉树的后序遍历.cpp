/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postorderTraversal(TreeNode* node, std::vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        // 左 -> 右 -> 根
        postorderTraversal(node->left, result);
        postorderTraversal(node->right, result);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};
// @lc code=end

