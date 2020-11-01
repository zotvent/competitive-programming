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
    
    TreeNode* x = NULL;
    TreeNode* y = NULL;
    TreeNode* pred = NULL;
    
    void findTwoSwapped(TreeNode* root) {
        if (!root) {
            return;
        }
        
        findTwoSwapped(root->left);
        
        if (pred && root->val < pred->val) {
            y = root;
            if (!x) x = pred;
            else return;
        }
        
        pred = root;
        findTwoSwapped(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        findTwoSwapped(root);
        swap(x->val, y->val);
    }
};