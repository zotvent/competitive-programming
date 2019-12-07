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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) binaryTreePaths(root, res, "");
        return res;
    }
    
    void binaryTreePaths(TreeNode* root, vector<string>& res, string cur) {
        cur += to_string(root->val);
        
        if (!root->left && !root->right) {
            res.push_back(cur);
            return;
        }
        
        cur += "->";
        if (root->left) binaryTreePaths(root->left, res, cur);
        if (root->right) binaryTreePaths(root->right, res, cur);
    }
};