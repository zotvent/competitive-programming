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
public:
    int closestValue(TreeNode* root, double target) {
        int res = 0;
        double dif = DBL_MAX;
        
        while (root) {
            if (abs(target - (double) root->val) < dif) {
                dif = abs(target - (double) root->val);
                res = root->val;
            }
            
            if (target == (double) root->val) {
                break;
            }
            else if (target < (double) root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        return res;
    }
};