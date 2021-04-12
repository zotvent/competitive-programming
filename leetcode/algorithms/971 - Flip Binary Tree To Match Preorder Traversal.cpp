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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        const int n = voyage.size();
        int i = 0;
        
        stack<TreeNode*> s;
        TreeNode* cur;
        s.push(root);
        
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            
            if (!cur) {
                continue;
            }
            
            if (cur->val != voyage[i]) {
                return {-1};
            }
            
            if (cur->left && cur->right && voyage[i + 1] == cur->right->val) {
                res.push_back(cur->val);
                s.push(cur->left);
                s.push(cur->right);
            }
            else {
                s.push(cur->right);
                s.push(cur->left);
            }
            
            i++;
        }
        
        return res;
    }
};