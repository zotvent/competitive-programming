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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, -1);
    }
    
    int dfs(TreeNode* root, int parent) {
        if (!root) return 0;
        
        int res = 0;
        
        if (parent % 2 == 0) {
            if (root->left) {
                res += root->left->val;
            }
            if (root->right) {
                res += root->right->val;
            }
        }
        
        res += dfs(root->left, root->val);
        res += dfs(root->right, root->val);
        
        return res;
    }
};