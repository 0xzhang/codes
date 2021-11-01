/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(root1&&root2){
            root1->val += root2->val;
            if(root1->left)
                mergeTrees(root1->left, root2->left);
            else root1->left = root2->left;
            if(root1->right)
                mergeTrees(root1->right, root2->right);
            else root1->right = root2->right;
        }
        return root1;
    }
};
// @lc code=end

