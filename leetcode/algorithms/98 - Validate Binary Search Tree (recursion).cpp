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
    
    void dfs(TreeNode* root, long long mx, long long mn, bool& res) {
        if (!root) {
            return;
        }
                
        if (root->val >= mx || root->val <= mn) {
            res = false;
            return;
        }
        
        dfs(root->left, root->val, mn, res);
        dfs(root->right, mx, root->val, res);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        bool res = true;
        dfs(root, LONG_MAX, LONG_MIN, res);
        return res;
    }
};