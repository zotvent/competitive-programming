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
    
    void dfs(TreeNode* root, map<int, map<int, multiset<int>>>& m, int x, int y) {
        if (!root) {
            return;
        }
        
        m[x][y].insert(root->val);
        dfs(root->left, m, x - 1, y - 1);
        dfs(root->right, m, x + 1, y - 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        dfs(root, m, 0, 0);
        
        vector<vector<int>> res;
        vector<int> report;
        
        for (auto i = m.begin(); i != m.end(); i++) {
            for (auto j = (i->second).rbegin(); j != (i->second).rend(); j++) {
                for (auto k = (j->second).begin(); k != (j->second).end(); k++) {
                    report.push_back(*k);
                }
            }
            res.push_back(report);
            report.clear();
        }
        
        return res;
    }
};