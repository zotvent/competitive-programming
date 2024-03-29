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
    
    bool dfs(TreeNode* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        
        if (dfs(root->left, target, seen) || seen.count(target - root->val) > 0) {
            return true;
        }
        seen.insert(root->val);
        return dfs(root->right, target, seen);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }
};