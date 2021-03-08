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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double sum;
        int cnt, size;
        TreeNode* cur;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            size = q.size();
            sum = 0;
            cnt = 0;
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                if (cur) {
                    sum += cur->val;
                    cnt++;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            
            if (cnt > 0) {
                res.push_back(sum / cnt);
            }
        }
        
        return res;
    }
};