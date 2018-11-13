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
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + dfs(root, sum, 0);
    }
    
    int dfs(TreeNode* root, int sum, int cur) {
        if (!root)
            return 0;
        cur += root->val;
        return (cur == sum ? 1 : 0) + dfs(root->left, sum, cur) + dfs(root->right, sum, cur);
    }
};