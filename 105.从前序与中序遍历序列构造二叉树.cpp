/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            index_[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }

    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right,
    int in_left, int in_right){
        if (pre_left > pre_right || in_left > in_right){
            return nullptr;
        }
        int inRoot = pre_left;  // 前序遍历的根节点（即最左侧节点）和中序遍历联系起来
        int positionRoot = index_[preorder[inRoot]];    // 根节点在中序遍历中的位置 元素唯一确定

        // 只要确定root 左右子树集合就确定了 「左子树长」即确定
        int lenLeftSubTree = positionRoot - in_left;   
        
        TreeNode* root = new TreeNode(preorder[inRoot]);

        root->left = myBuildTree(preorder, inorder, 
                                pre_left + 1, inRoot + lenLeftSubTree,
                                in_left, positionRoot -1);

        root->right = myBuildTree(preorder, inorder,
                                pre_left + lenLeftSubTree + 1, pre_right,
                                positionRoot + 1, in_right);
        
        return root;
    }

private:
    unordered_map<int, int> index_;
};
// @lc code=end

