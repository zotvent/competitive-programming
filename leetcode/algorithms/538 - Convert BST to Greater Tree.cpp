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
    
    pair<TreeNode*, int> dfs(TreeNode* root, int sum) {
        if (!root) {
            return {root, sum};
        }
        
        pair<TreeNode*, int> right = dfs(root->right, sum);
        pair<TreeNode*, int> left = dfs(root->left, root->val + right.second);
        root->val += right.second;
        
        return {root, left.second};
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        pair<TreeNode*, int> res = dfs(root, 0);
        return res.first;
    }
};