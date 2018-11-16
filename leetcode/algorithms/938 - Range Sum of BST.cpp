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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root) {
            int sum = 0;
            if (L <= root->val && root->val <= R)
                sum = root->val;
            return sum + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
        return 0;
    }
};