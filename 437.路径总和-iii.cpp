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
        traversal(root, targetSum - root->val);   // 递归+回溯
        if (root->left) pathSum(root->left, targetSum);
        if (root->right) pathSum(root->right, targetSum);
        return res_;
    }

    void traversal(TreeNode* cur, long long count) {
        // 对 count 变量使用了 long long 类型，以确保在大数情况下不会发生溢出
        if (!cur) return;   
        if (count == 0) res_++;
        // cout << cur->val << ":" << count << endl;

        if (cur->left)
        {
            count -= cur->left->val;
            // cout << cur->val << ":" << cur->left->val << endl;
            traversal(cur->left, count);
            count += cur->left->val;
        } 
        if (cur->right)
        {
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;   
        }  
    }
};
// @lc code=end

