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
    vector<int> inorder, postorder;
    unordered_map<int, int> in;
    int postIndex;
    
    TreeNode* dfs(int l, int r) {
        if (r < l) {
            return NULL;
        }
        
        int value = postorder[postIndex];
        TreeNode* root = new TreeNode(value);
        
        int index = in[value];
        postIndex--;
        
        root->right = dfs(index + 1, r);
        root->left = dfs(l, index - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }
        
        postIndex = postorder.size() - 1;
        
        return dfs(0, inorder.size() - 1);
    }
};