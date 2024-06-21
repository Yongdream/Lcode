/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        // 队列来存储待访问的节点
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> cur;    // 当前层要弹出的节点
            while (size--)
            {
                TreeNode* node = q.front();
                q.pop();    // 弹出队列前端的节点

                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(cur); // 将当前层的节点值向量加入结果
        }
        reverse(res.begin(), res.end()); // 在这里反转一下数组即可
        return res;
    }
};
// @lc code=end

