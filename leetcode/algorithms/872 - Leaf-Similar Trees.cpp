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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        dfs(root1, leaves1);
        dfs(root2, leaves2);

        if (leaves1.size() != leaves2.size()) 
            return false;
        else {
            for (int i = 0; i < leaves1.size(); i++)
                if (leaves1[i] != leaves2[i])
                    return false;
        }

        return true;
    }

    void dfs(TreeNode* root, vector<int>& leaves) {
        if (root) {
            if (!root->left && !root->right)
                leaves.push_back(root->val);
            else {
                dfs(root->left, leaves);
                dfs(root->right, leaves);
            }
        }
    }
};