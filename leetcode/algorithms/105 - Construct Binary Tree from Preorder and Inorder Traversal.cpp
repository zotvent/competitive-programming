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
    
    TreeNode* buildTree(int& head, vector<int>& preorder, unordered_map<int, int>& in, int l, int r) {
        if (l > r) return NULL;
        
        TreeNode* res = new TreeNode(preorder[head]);
        int m = in[preorder[head++]];
        res->left = buildTree(head, preorder, in, l, m - 1);
        res->right = buildTree(head, preorder, in, m + 1, r);
        return res; 
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int head = 0;
        unordered_map<int, int> in;
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        return buildTree(head, preorder, in, 0, inorder.size() - 1);
    }
};