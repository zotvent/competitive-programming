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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int cur = 0;
        return dfs(preorder, cur, INT_MIN, INT_MAX);
    }
    
    TreeNode* dfs(vector<int>& preorder, int& cur, int mn, int mx) {
        if (cur >= preorder.size()) {
            return NULL;
        }
        
        if (preorder[cur] < mn || preorder[cur] > mx) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[cur++]);
        root->left = dfs(preorder, cur, mn, root->val);
        root->right = dfs(preorder, cur, root->val, mx);
        
        return root;
    }
};