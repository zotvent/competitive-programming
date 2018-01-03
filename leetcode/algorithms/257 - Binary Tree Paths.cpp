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
        if (root)
            dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* root, string s, vector<string> &v) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            v.push_back(s + to_string(root->val));
            return;
        }
        
        dfs(root->left, s + to_string(root->val) + "->", v);
        dfs(root->right, s + to_string(root->val) + "->", v);
    }
};