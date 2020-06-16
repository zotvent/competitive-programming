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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    
    bool dfs(TreeNode* root, int parent, int& res) {
        if (!root) {
            return true;
        }
        
        bool left = dfs(root->left, root->val, res);
        bool right = dfs(root->right, root->val, res);
        
        if (!left || !right) {
            return false;
        }
        
        res++;
        
        return root->val == parent;
    }
};