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
    TreeNode* bstFromPreorder(vector<int>& preorder) { 
        return build(preorder, 0, INT_MIN, INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder, int index, int min_value, int max_value) {
        if (index >= preorder.size()) {
            return NULL;
        }
        
        TreeNode* node = NULL;
                
        for (int i = index; i < preorder.size(); i++) {
            if (preorder[i] > min_value && preorder[i] < max_value) {
                node = new TreeNode(preorder[i]);
                node->left = build(preorder, i + 1, min_value, node->val);
                node->right = build(preorder, i + 1, node->val, max_value);
                break;
            }
        }
        
        return node;
    }
};