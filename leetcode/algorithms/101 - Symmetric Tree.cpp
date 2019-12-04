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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        bool res = true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        while (!q.empty()) {
            left = q.front(); q.pop();
            right = q.front(); q.pop();
            
            if (left && right) {
                if (left->val != right->val) {
                    res = false;
                    break;
                }
                else {
                    q.push(left->left);
                    q.push(right->right);
                    
                    q.push(left->right);
                    q.push(right->left);
                }
            }
            else if (!left && !right) {}
            else {
                res = false;
                break;
            }
        }
        
        return res;
    }
};