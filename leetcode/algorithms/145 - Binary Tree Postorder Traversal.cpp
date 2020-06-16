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
        
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        
        pair<TreeNode*, int> v;
        
        while (!s.empty()) {
            v = s.top();
            s.pop();
            
            if (v.first) {
                if (v.second == 2) {
                    res.push_back(v.first->val);
                }
                else {
                    v.second++;
                    s.push(v);
                    s.push({v.first->right, 1});
                    s.push({v.first->left, 1});
                }
            }
        }
        
        return res;
    }
};