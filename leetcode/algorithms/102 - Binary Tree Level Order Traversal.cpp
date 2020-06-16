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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int sz;
        TreeNode* v;
        
        while (!q.empty()) {
            sz = q.size();
            
            while (sz > 0) {
                v = q.front();
                q.pop();
                
                if (v) {
                    level.push_back(v->val);
                    q.push(v->left);
                    q.push(v->right);
                }
                
                sz--;
            }
            
            if (!level.empty()) {
                res.push_back(level);
                level.clear();
            }
        }
        
        return res;
    }
};