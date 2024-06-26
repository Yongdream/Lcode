/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        // 中序 由小变大
        if (root == NULL) return true;
        bool left = isValidBST(root->left);
        if (maxVal_ < root->val) maxVal_ = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left&&right;
    }
private:
    long maxVal_ = LONG_MIN;
};
// @lc code=end


