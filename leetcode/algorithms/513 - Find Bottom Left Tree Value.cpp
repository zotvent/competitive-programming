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
    int findBottomLeftValue(TreeNode* root) {
        int min = -1, res;
        dfs(root, 0, min, res);
        return res;
    }
    
    void dfs(TreeNode* root, int depth, int &min, int &res) {
        if (root) {
            if (depth > min) {
                min = depth;
                res = root->val;
            }
            dfs(root->left, depth + 1, min, res);
            dfs(root->right, depth + 1, min, res);
        }
    }
};