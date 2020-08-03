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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int size, index;
        TreeNode* v;
        vector<int> level;
        bool fromLeftToRight = true;
        
        while (!q.empty()) {
            size = q.size();
            level.resize(size);
            
            for (int i = 0; i < size; i++) {
                v = q.front();
                q.pop();
                
                index = (fromLeftToRight ? i : size - i - 1);
                level[index] = v->val;
                
                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
            }
            
            res.push_back(level);
            fromLeftToRight = !fromLeftToRight;
        }
        
        return res;
    }
};