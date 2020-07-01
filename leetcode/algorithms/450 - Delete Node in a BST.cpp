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
    
    TreeNode* findLeftMost(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        
        if (root->val == key) {
            if (!root->right) {
                return root->left;
            }
            
            if (!root->left) {
                return root->right;
            }
            
            TreeNode* leftMost = findLeftMost(root->right);
            root->val = leftMost->val;
            root->right = deleteNode(root->right, leftMost->val);
        }
        
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        
        return root;
    }
};