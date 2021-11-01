/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // Recursive
        // inorder(res, root);

        // Iterative with stack
        // stack<TreeNode*> st;
        // while(root||st.size()){
        //     while(root){
        //         st.push(root);
        //         root=root->left;
        //     }
        //     root = st.top();
        //     st.pop();
        //     res.push_back(root->val);
        //     root = root->right;
        // }

        // ??Morris's traversal
        while(root){
            if(root->left){
                TreeNode* pre = root->left;
                while(pre->right&&pre->right!=root) pre=pre->right;
                if(!pre->right){
                    pre->right=root;
                    root=root->left;
                }else{
                    pre->right = nullptr;
                    res.push_back(root->val);
                    root=root->right;
                }

            }else{
                res.push_back(root->val);
                root = root->right;
            }
        }

        return res;
    }
private:
    __attribute__((always_inline)) void inorder(vector<int>& res, TreeNode* root){
        if(!root) return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
};
// @lc code=end

