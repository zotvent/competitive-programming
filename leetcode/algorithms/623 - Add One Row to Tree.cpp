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
    
    TreeNode* rec(TreeNode* root, int v, int d, int depth) {
        if (!root) {
            return root;
        }
        
        if (d == 1) {
            TreeNode* res = new TreeNode(v);
            res->left = root;
            return res;
        }
        
        if (depth == d - 1) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(v);
            root->right = new TreeNode(v);
            root->left->left = left;
            root->right->right = right;
        }
        else {
            root->left = rec(root->left, v, d, depth + 1);
            root->right = rec(root->right, v, d, depth + 1);
        }
        
        return root;
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return rec(root, v, d, 1);
    }
};