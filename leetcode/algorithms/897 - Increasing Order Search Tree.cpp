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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        TreeNode* tail = head;
        inorder(root, tail);
        return head->right;
    }

    void inorder(TreeNode* root, TreeNode* &tail) {
        if (root) {
            inorder(root->left, tail);
            root->left = NULL;
            tail->right = root;
            tail = root;
            inorder(root->right, tail);
        }
    }
};