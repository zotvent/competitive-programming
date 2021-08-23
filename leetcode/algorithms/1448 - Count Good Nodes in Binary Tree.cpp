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
    
    void dfs(TreeNode* root, int& res, int mx) {
        if (!root) return;
        
        if (root->val >= mx) res++;
        mx = max(root->val, mx);
        dfs(root->left, res, mx);
        dfs(root->right, res, mx);
    }
    
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, res, INT_MIN);
        return res;
    }
};