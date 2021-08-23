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
    
    long long dfs(TreeNode* root, vector<long long> &sums) {
        if (!root) return 0;
        
        long long left = dfs(root->left, sums);
        long long right = dfs(root->right, sums);
        long long sum = left + right + root->val;
        
        sums.push_back(sum);
        return sum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        if (!root) return 0;
        
        vector<long long> sums;
        dfs(root, sums);
        
        const int n = (int) sums.size() - 1;
        const int mod = 1e9 + 7;
        long long res = 0;
        
        for (int i = 0; i < n; i++) {
            res = max(res, sums[i] * (sums[n] - sums[i]));
        }
                
        return res % mod;
    }
};