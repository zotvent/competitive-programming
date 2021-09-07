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
    
    void update(double& res, pair<double, double> cur) {
        if (cur.second != 0) {
            res = max(res, cur.first / cur.second);
        }
    }
    
    pair<double, double> dfs(TreeNode* root, double& res) {
        if (!root) return {0, 0};
        
        auto left = dfs(root->left, res);
        update(res, left);
        auto right = dfs(root->right, res);
        update(res, right);
        pair<double, double> ans = {left.first + right.first + root->val, left.second + right.second + 1};
        update(res, ans);
        return ans;
    }
    
public:
    double maximumAverageSubtree(TreeNode* root) {
        double res = 0;
        dfs(root, res);
        return res;
    }
};