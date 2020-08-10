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
    
    void rec(TreeNode* root, int target, int sum, unordered_map<int, int>& m, int& res) {
        if (!root) {
            return;
        }
        
        sum += root->val;
        
        if (target == sum) {
            res++;
        }
        
        res += m[sum - target];
        m[sum]++;
        
        rec(root->left, target, sum, m, res);
        rec(root->right, target, sum, m, res);
        
        m[sum]--;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        
        unordered_map<int, int> m;
        rec(root, sum, 0, m, res);
        
        return res;
    }
};