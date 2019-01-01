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
    bool isUnivalTree(TreeNode* root) {
        return dfs(root);
    }
    
    bool dfs(TreeNode* root, int prev = -1) {
        if (!root) return true;
        
        bool res = dfs(root->left, root->val) && dfs(root->right, root->val); 
        if (prev == -1)
            return res;
        else
            return root->val == prev && res;
    }
};