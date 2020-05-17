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
private:
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> m;
    int head;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        
        head = 0;
        return calc(0, inorder.size());
    }
    
    TreeNode* calc(int l, int r) {        
        if (l == r) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[head]);
        
        int split_index = m[preorder[head++]];
        
        root->left = calc(l, split_index);
        root->right = calc(split_index + 1, r);
        
        return root;
    }
};