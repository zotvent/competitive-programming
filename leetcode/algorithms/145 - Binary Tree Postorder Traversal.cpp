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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* v;
        
        while (!s.empty()) {
            v = s.top();
            s.pop();
            
            if (v) {
                res.push_back(v->val);
                s.push(v->left);
                s.push(v->right);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};