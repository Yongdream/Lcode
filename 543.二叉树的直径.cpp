/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        maxdiameter_ = 0;
        depthAndDiameter(root);
        return maxdiameter_;
    }

private:
    int maxdiameter_;
    int depthAndDiameter(TreeNode* root) {
        if (root == nullptr) return 0;

        // 前序遍历
        // 递归计算左子树和右子树的深度
        int leftDepth = depthAndDiameter(root->left);
        int rightDepth = depthAndDiameter(root->right);

        // 更新最大直径，当前节点的左子树深度与右子树深度之和
        maxdiameter_ = std::max(maxdiameter_, leftDepth + rightDepth);

        // 返回以node为根的子树的最大深度
        return std::max(leftDepth, rightDepth) + 1;
    }

};
// @lc code=end

