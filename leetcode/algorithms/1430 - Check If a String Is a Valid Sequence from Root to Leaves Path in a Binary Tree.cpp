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
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
    
    bool dfs(TreeNode* root, vector<int>& arr, int index) {
        if (!root) {
            return index == arr.size();
        }
        if (index == arr.size()) {
            return root == NULL;
        }
        
        if (root->val != arr[index]) {
            return false;
        }
        
        if (root->left && root->right) {
            bool left = dfs(root->left, arr, index + 1);
            bool right = dfs(root->right, arr, index + 1);
            
            return left || right;
        }
        else if (root->left) {
            return dfs(root->left, arr, index + 1);
        }
        else {
            return dfs(root->right, arr, index + 1);
        }        
    }
};