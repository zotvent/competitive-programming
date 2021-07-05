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
    
    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return 1;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int height = max(left, right);
        
        if (res.size() >= height) {
            res[height - 1].push_back(root->val);
        }
        else {
            res.push_back({root->val});
        }
        
        return height + 1;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};