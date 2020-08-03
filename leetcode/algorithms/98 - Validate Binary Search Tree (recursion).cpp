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
    
    bool dfs(TreeNode* root, long long minValue, long long maxValue) {
        if (!root) {
            return true;
        }
        
        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }
        
        bool left = dfs(root->left, minValue, root->val);
        bool right = dfs(root->right, root->val, maxValue);
        
        return left && right;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        long long minValue = -1L + INT_MIN; 
        long long maxValue = 1L + INT_MAX;
        return dfs(root, minValue, maxValue);
    }
};