/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // dfs1
        int h = nums.size()/2;
        TreeNode* root = new TreeNode(nums[h]);
        dfs(root, nums, 0, h-1, h+1, nums.size()-1);
        return root;
        
        // dfs2
        // return dfs2(nums, 0, nums.size());
    }
private:
    __attribute__((always_inline)) void dfs(TreeNode* root, const vector<int>& nums, int ls, int le, int rs, int re){
        if(ls<=le){
            int n = le-ls+1;
            TreeNode* node = new TreeNode(nums[ls+n/2]);
            root->left = node;
            dfs(node, nums, ls, ls+n/2-1, ls+n/2+1, le);
        }
        if(rs<=re){
            int n = re-rs+1;
            TreeNode* node = new TreeNode(nums[rs+n/2]);
            root->right = node;
            dfs(node, nums, rs, rs+n/2-1, rs+n/2+1, re);
        }
    }

    __attribute__((always_inline)) TreeNode* dfs2(const vector<int>& nums, int st, int ed){
        if(ed<=st) return nullptr;
        int m = (ed+st)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = dfs2(nums, st, m);
        root->right = dfs2(nums, m+1, ed);
        return root;
    }
};
// @lc code=end

