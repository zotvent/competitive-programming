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
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        TreeNode* cur = res;
        stack<TreeNode*> s;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            cur->right = root;
            cur = cur->right;
            cur->left = NULL;
            
            root = root->right;
        }
        
        return res->right;
    }
};