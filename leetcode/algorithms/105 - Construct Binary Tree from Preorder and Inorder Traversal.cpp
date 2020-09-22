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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& in, int& head, int left, int right) {
        if (left > right) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[head]);
        int rootIndex = in[preorder[head++]];
        
        root->left = buildTree(preorder, inorder, in, head, left, rootIndex - 1);
        root->right = buildTree(preorder, inorder, in, head, rootIndex + 1, right);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in;
        int head = 0;
        const int n = inorder.size();
        
        for (int i = 0; i < n; i++) {
            in[inorder[i]] = i;
        }
        
        return buildTree(preorder, inorder, in, head, 0, n - 1);
    }
};