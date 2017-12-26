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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<int>> &g, int depth) {
        if (!root)
            return;
        
        if (g.size() <= depth)
            g.resize(depth+1);
        
        g[depth].push_back(root->val);
        
        dfs(root->left, g, depth+1);
        dfs(root->right, g, depth+1);
    }
};