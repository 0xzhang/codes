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
        vector<int> res;
        inorder(root, k, res);
        return res[k-1];
        
        // return find(root, k);
    }
private:
    void inorder(TreeNode* root, int k, vector<int>& res){
        if(!root||res.size()>=k) return;
        inorder(root->left, k, res);
        res.push_back(root->val);
        inorder(root->right, k, res);
    }

    int find(TreeNode* root, int& k){
        if(root){
            int x = find(root->left, k);
            return !k ? x : !--k? root->val : find(root->right, k);
        }
        return 999;
    }
};
// @lc code=end

