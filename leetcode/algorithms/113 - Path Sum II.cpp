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
    
    void dfs(TreeNode* root, int targetSum, vector<int>& cur, int sum, vector<vector<int>>& res) {
        cur.push_back(root->val);
        sum += root->val;
        
        if (root->left) dfs(root->left, targetSum, cur, sum, res);
        if (root->right) dfs(root->right, targetSum, cur, sum, res);
        
        if (!root->left && !root->right && sum == targetSum && !cur.empty()) {
            res.push_back(cur);
        }
        
        cur.pop_back();
        sum -= root->val;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, targetSum, cur, 0, res);
        return res;
    }
};