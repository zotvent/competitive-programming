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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(s, root);
        if (s.size() > 1) {
            auto it = s.begin();
            it++;
            return *it;
        }
        else
            return -1;
    }
    
    void dfs(set<int> &s, TreeNode* &root) {
        if (root != NULL) {
            s.insert(root->val);
            dfs(s, root->left);
            dfs(s, root->right);
        }
    }
};