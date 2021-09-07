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
    
    vector<TreeNode*> rec(int start, int end) {
        if (start > end) {
            return {NULL};
        }
        
        vector<TreeNode*> res;
        vector<TreeNode*> leftTrees, rightTrees;
        TreeNode* root;
        
        for (int i = start; i <= end; i++) {
            leftTrees = rec(start, i - 1);
            rightTrees = rec(i + 1, end);
            
            for (auto& left: leftTrees) {
                for (auto& right: rightTrees) {
                    root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return rec(1, n);
    }
};