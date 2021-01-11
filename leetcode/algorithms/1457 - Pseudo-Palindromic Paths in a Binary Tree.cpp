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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0, path = 0;
        stack<pair<TreeNode*, int>> s;
        pair<TreeNode*, int> top;
        TreeNode* node = NULL;
        
        s.push({root, 0});
        
        while (!s.empty()) {
            top = s.top(); s.pop();
            node = top.first;
            path = top.second;
            
            if (node) {
                path = path ^ (1 << node->val);
                
                if (!node->left && !node->right) {
                    if ((path & (path - 1)) == 0) {
                        res++;
                    }
                }
                else {
                    s.push({node->left, path});
                    s.push({node->right, path});
                }
            }
        }
        
        return res;
    }
};