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
    
    // [rob this node, not rob this node]
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        int rob = root->val + left[1] + right[1];
        int notRob = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {rob, notRob};
    }
    
public:
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};