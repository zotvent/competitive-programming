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
private:
    int const mod = (int) 1e9 + 7;
    
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur) {
        if (!root) return 0;
        cur = ((cur << 1) + root->val) % mod;
        return root->left == root->right ? cur : (dfs(root->left, cur) + dfs(root->right, cur)) % mod;
    }
};