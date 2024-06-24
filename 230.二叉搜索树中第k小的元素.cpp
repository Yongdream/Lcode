/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        dfs(root, k, result);
        return result;
    }
private:
    void dfs (TreeNode* node, int& k, int& res){
        if (node == nullptr) return;
        // 二叉搜索树性质 中序:由小到大
        dfs(node->left, k, res);
        k--;
        if (k == 0)
        {
            res = node->val;
            return;
        }
        dfs(node->right, k, res);
    }
};
// @lc code=end

