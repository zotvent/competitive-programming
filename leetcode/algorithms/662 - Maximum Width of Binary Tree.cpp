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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long res = 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        int size;
        unsigned long long mn;
        pair<TreeNode*, int> v;
        
        while (!q.empty()) {
            size = q.size();
            mn = q.front().second;
            
            while (size > 0) {
                v = q.front();
                q.pop();
                
                if (v.first->left) {
                    q.push({v.first->left, v.second * 2UL});
                }
                if (v.first->right) {
                    q.push({v.first->right, v.second * 2UL + 1UL});
                }
                
                size--;
            }
            
            res = max(res, v.second - mn + 1);
        }
        
        return (int) res;
    }
};