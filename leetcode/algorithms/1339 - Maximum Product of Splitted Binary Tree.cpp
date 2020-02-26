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
    int maxProduct(TreeNode* root) {
        if (!root) return 0;
        
        vector<long long> sum;
        calc_sum(root, sum);
        int n = (int) sum.size() - 1;
        
        long long res = 0;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            res = max(res, sum[i] * (sum[n] - sum[i]));
        }
                
        return (int) (res % mod);
    }
    
    long long calc_sum(TreeNode* root, vector<long long> &sum) {
        if (!root) return 0;
        
        long long left = calc_sum(root->left, sum);
        long long right = calc_sum(root->right, sum);
        long long s = left + right + root->val;
        
        sum.push_back(s);
        return s;
    }
};