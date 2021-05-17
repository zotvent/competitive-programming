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
    
    // camera, connection type to the camera (0 - camera in the current node, 1 - camera in the child, 2 - no camera)
    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 2};
        }
        if (!root->left && !root->right) {
            return {0, 2};
        }
        
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        if ((left.second == 2 && root->left) || (right.second == 2 && root->right)) {
            return {left.first + right.first + 1, 0};
        }
        else if ((left.second == 1 && root->left) && (right.second == 1 && root->right) ||
                 (left.second == 1 && root->left && !root->right) ||
                 (right.second == 1 && root->right && !root->left)) {
            return {left.first + right.first, 2};
        }
        else {
            return {left.first + right.first, 1};
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        pair<int, int> res = dfs(root);
        if (res.second == 2) {
            res.first++;
        }
        return res.first;
    }
};