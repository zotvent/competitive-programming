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
    
    int sum(TreeNode* root, unordered_map<TreeNode*, int>& memo) {
        if (!root) return 0;
        if (memo.count(root) > 0) return memo[root];
        
        int left = sum(root->left, memo);
        int right = sum(root->right, memo);
        return memo[root] = left + right + root->val;
    }
    
    bool dfs(TreeNode* root, unordered_map<TreeNode*, int>& memo, int prev) {
        if (!root || (!root->left && !root->right)) return false;
        
        int left = sum(root->left, memo);
        int right = sum(root->right, memo);
        if ((root->right && prev + root->val + left == right) ||
            (left && prev + root->val + right == left)) {
            return true;
        }
        
        return dfs(root->left, memo, prev + root->val + right) || dfs(root->right, memo, prev + root->val + left);
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return dfs(root, memo, 0);
    }
};