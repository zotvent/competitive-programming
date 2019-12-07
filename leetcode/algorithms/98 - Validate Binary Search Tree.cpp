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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* last = NULL;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            if (last && root->val <= last->val) return false;
            last = root;
            root = root->right;
        }
        
        return true;
    }
};