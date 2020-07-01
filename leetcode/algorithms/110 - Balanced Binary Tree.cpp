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
    
    int dfs(TreeNode* root, bool& res) {
        if (!root) {
            return 0;
        }
        
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        
        if (abs(left - right) > 1) {
            res = false;
        }
        
        return 1 + max(left, right);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};