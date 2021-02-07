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
    
    bool equals(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && equals(s->left, t->left) && equals(s->right, t->right);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return s && (equals(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
    }
};