/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);

        while (!que.empty())
        {
            int layerSize = que.size();
            for (int i = 0; i < layerSize; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                if (i == (layerSize - 1))
                {
                    res.push_back(node->val);   // 将当前层最后节点值向量加入结果
                }
                if (node->left) que.push(node->left);   // 如果有值就加入队列维护
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end

