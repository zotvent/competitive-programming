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

    void dfs(TreeNode* root, int mn, int mx, int &res) {
        if (!root) {
            res = max(res, mx - mn);
            return;
        }
        
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        
        dfs(root->left, mn, mx, res);
        dfs(root->right, mn, mx, res);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        dfs(root, root->val, root->val, res);
        return res;
    }
};