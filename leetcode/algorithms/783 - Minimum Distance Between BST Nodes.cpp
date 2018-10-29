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
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prev = -1;
        dfs(root, res, prev);
        return res;
    }

    void dfs(TreeNode* root, int &res, int &prev) {
        if (root) {
            dfs(root->left, res, prev);

            if (prev != -1)
                res = min(res, root->val - prev);
            prev = root->val;

            dfs(root->right, res, prev);
        }
    }
};