/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> pos;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(!n) return NULL;
        
        for(int i=0; i<n; ++i)
            pos[inorder[i]] = i;
            
        return rec(preorder, inorder, 0, n, 0, n);
    }
    
    TreeNode* rec(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir) {
        if(pl >= pr) return NULL;
        
        int k = pos[pre[pl]] - il;
        TreeNode* root = new TreeNode(pre[pl]);
        root->left = rec(pre, in, pl+1, pl+k+1, il, il+k);
        root->right = rec(pre, in, pl+k+1, pr, il+k+1, ir);
        
        return root;
    }
};