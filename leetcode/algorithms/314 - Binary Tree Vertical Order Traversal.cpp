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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            int col = cur.second;
            m[col].push_back(cur.first->val);
            if (cur.first->left) q.push({cur.first->left, col - 1});
            if (cur.first->right) q.push({cur.first->right, col + 1});
        }
        
        vector<vector<int>> res;
        
        for (auto& i: m) {
            res.push_back(i.second);
        }
        
        return res;
    }
};