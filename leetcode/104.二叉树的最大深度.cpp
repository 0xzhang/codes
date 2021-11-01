/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 不能通过队列+循环记录的节点数来确定层数，因为并非是完全二叉树
    int res = 0;
    int maxDepth(TreeNode* root) {
        // dfs(1, root);
        // return res;
        return root ? 1+max(maxDepth(root->left), maxDepth(root->right)):0;
    }
private:
    __attribute__((always_inline)) void dfs(int level, TreeNode* r){
        if(!r) return;
        if(!r->left && !r->right){
            if(level>res) res=level;
            return;
        }
        if(r->left) dfs(level+1, r->left);
        if(r->right) dfs(level+1, r->right);
    }
};
// @lc code=end

