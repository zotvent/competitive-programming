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
    
    pair<TreeNode*, int> rec(TreeNode* root, int depth) {
        if (!root) {
            return {root, depth};
        }
        
        pair<TreeNode*, int> left = rec(root->left, depth + 1);
        pair<TreeNode*, int> right = rec(root->right, depth + 1);
        
        if (!left.first && !right.first) {
            return {root, depth};
        }
        else if (!left.first) {
            return right;
        }
        else if (!right.first) {
            return left;
        }
        else if (left.second == right.second) {
            return {root, left.second};
        }
        else if (left.second > right.second) {
            return left;
        }
        else {
            return right;
        }
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*, int> res = rec(root, 0);
        return res.first;
    }
};