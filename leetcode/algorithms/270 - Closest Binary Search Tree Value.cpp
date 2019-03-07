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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        
        while (root) {
            double val = root->val;
            
            double old_dif = abs(target - res);
            double dif = abs(target - val);
            
            if (dif < old_dif) {
                res = val;
            }
            
            if (target == val) {
                res = val;
                break;
            }
            else if (target > val) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        
        return res;
    }
};