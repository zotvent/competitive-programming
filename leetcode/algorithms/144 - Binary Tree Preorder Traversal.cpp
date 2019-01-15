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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        
        s.push(root);
        while (!s.empty()) {
            TreeNode* top = s.top();
            s.pop();
            
            if (top) {
                res.push_back(top->val);
                s.push(top->right);
                s.push(top->left);
            }
        }
        
        return res;
    }
};