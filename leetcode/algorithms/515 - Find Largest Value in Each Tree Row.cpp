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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 1, res);
        return res;
    }
    
    void dfs(TreeNode* root, int depth, vector<int> &res) {
        if (root) {
            if (res.size() < depth)
                res.push_back(root->val);
            else
                res[depth - 1] = max(res[depth - 1], root->val);
            
            dfs(root->left, depth + 1, res);
            dfs(root->right, depth + 1, res);
        }
    }
};