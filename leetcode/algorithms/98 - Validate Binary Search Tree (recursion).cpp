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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        bool res = true;
        dfs(root, res);
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root, bool& res) {
        pair<int, int> p = make_pair(root->val, root->val);
        
        if (root->left) {
            pair<int, int> left = dfs(root->left, res);
            if (left.second >= root->val) res = false;
            p.first = min(left.first, p.first);
        }
        
        if (root->right) {
            pair<int, int> right = dfs(root->right, res);
            if (right.first <= root->val) res = false;
            p.second = max(right.second, p.second);
        }
        
        return p;
    }
};