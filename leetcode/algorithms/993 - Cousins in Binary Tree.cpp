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
    
    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* parent, int val, int height) {
        if (!root) return {NULL, height};
        
        if (root->val == val) {
            return {parent, height};
        }
        
        auto left = dfs(root->left, root, val, height + 1);
        
        if (left.first) return left;
        else return dfs(root->right, root, val, height + 1);
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto X = dfs(root, NULL, x, 0);
        auto Y = dfs(root, NULL, y, 0);
        return X.second == Y.second && X.first != Y.first;
    }
};