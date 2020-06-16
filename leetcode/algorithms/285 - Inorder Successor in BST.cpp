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
    
    TreeNode* res;
    
    void dfs(TreeNode* root, TreeNode* p) {
        if (!root) {
            return;
        }
        
        if (root->val > p->val) {
            if (!res || res->val > root->val) {
                res = root;
            }
        }
        
        if (root->val <= p->val) {
            dfs(root->right, p);
        }
        else {
            dfs(root->left, p);
        }
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return NULL;
        }
        
        res = NULL;
        dfs(root, p);
        return res;
    }
};