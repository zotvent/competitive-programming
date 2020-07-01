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
    
    void dfs(TreeNode* root, int& res, int cur) {
        if (!root) {
            return;
        }
        
        cur = cur * 10 + root->val;
        
        if (!root->left && !root->right) {
            res += cur;
        }
        else {
            dfs(root->left, res, cur);
            dfs(root->right, res, cur);
        }
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
};