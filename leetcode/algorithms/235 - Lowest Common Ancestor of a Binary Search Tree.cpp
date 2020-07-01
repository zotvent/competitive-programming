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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p) return q;
        if (!q) return p;
        
        TreeNode* cur = root;
        int pVal = p->val;
        int qVal = q->val;
        int curVal;
        
        while (cur) {
            curVal = cur->val;
            
            if (curVal < pVal && curVal < qVal) {
                cur = cur->right;
            }
            else if (curVal > pVal && curVal > qVal) {
                cur = cur->left;
            }
            else {
                return cur;
            }
        }
        
        return NULL;
    }
};