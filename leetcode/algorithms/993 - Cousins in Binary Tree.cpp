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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> left = {-2, -2}; // depth, parent
        pair<int, int> right = {-3, -3}; // depth, parent
        
        dfs(root, x, 0, 0, left);
        dfs(root, y, 0, -1, right);
        
        return left.first == right.first && left.second != right.second;
    }
    
    void dfs(TreeNode* root, int x, int h, int p, pair<int, int>& res) {
        if (!root) return;
        
        if (root->val == x) {
            res = {h, p};
            return;
        }
        
        dfs(root->left, x, h + 1, root->val, res);
        dfs(root->right, x, h + 1, root->val, res);
    }
};