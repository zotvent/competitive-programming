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
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return find(root, k, s);
    }
    
    bool find(TreeNode* root, int k, set<int> &s) {
        if (root == NULL)
            return false;
        
        if (s.find(k-root->val) != s.end())
            return true;
        
        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
};