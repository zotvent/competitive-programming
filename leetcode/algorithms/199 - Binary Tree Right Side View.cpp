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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        TreeNode* cur;
        int size;
        bool rightMost;
        
        q.push(root);
        
        while (!q.empty()) {
            size = q.size();
            rightMost = true;
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();

                if (cur) {
                    if (rightMost) {
                        res.push_back(cur->val);
                        rightMost = false;
                    }
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        
        return res;
    }
};