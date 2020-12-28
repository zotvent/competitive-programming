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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* prev = NULL;
        TreeNode* cur = NULL;
        int size;
        
        while (!q.empty()) {
            size = q.size();
            prev = NULL;
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                if (!cur) continue;
                
                if (prev == u) {
                    return cur;
                }
                
                prev = cur;
                
                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        
        return NULL;
    }
};