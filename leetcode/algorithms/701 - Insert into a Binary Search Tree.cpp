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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        return root;
    }

    void insert(TreeNode* &root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }

        if (root->val > val) insert(root->left, val);
        else insert(root->right, val);
    }
};