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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        
        queue<TreeNode*> q;
        int size;
        TreeNode* cur;
        
        if (root) q.push(root);
        
        while (!q.empty()) {
            size = q.size();
            res = 0;
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                res += cur->val;
                
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        
        return res;
    }
};