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
    
    int leftDepth(TreeNode* root) {
        int res = 0;
        
        while (root) {
            root = root->left;
            res++;
        }
        
        return res;
    }
    
    int rightDepth(TreeNode* root) {
        int res = 0;
        
        while (root) {
            root = root->right;
            res++;
        }
        
        return res;
    }
    
public:
    int countNodes(TreeNode* root) {
        int left = leftDepth(root);
        int right = rightDepth(root);
        
        if (left == right) {
            return (1 << left) - 1;
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};