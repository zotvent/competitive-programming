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
    int maxDepth(TreeNode* root) {
        if (root) {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return 1 + max(left, right);
        }
        else return 0;
    }
};