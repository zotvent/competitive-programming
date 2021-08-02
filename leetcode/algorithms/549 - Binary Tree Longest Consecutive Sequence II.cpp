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
    
    vector<int> rec(TreeNode* root, int& res) {
        if (!root) {
            return {0, 0};
        }
        
        int inc = 1, dec = 1;
        
        if (root->left) {
            vector<int> left = rec(root->left, res);
            
            if (root->val == root->left->val + 1) {
                dec = left[1] + 1;
            }
            else if (root->val == root->left->val - 1) {
                inc = left[0] + 1;
            }
        }
        
        if (root->right) {
            vector<int> right = rec(root->right, res);
            
            if (root->val == root->right->val + 1) {
                dec = max(dec, right[1] + 1);
            }
            else if (root->val == root->right->val - 1) {
                inc = max(inc, right[0] + 1);
            }
        }
        
        res = max(res, inc + dec - 1);
        
        return {inc, dec};
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        rec(root, res);
        return res;
    }
};