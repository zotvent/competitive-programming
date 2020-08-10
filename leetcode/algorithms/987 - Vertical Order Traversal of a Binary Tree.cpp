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
    
    void rec(TreeNode* root, map<int, map<int, multiset<int>>>& m, int x, int y) {
        if (!root) {
            return;
        }
        
        rec(root->left, m, x - 1, y - 1);
        rec(root->right, m, x + 1, y - 1);
        
        m[x][y].insert(root->val);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        
        map<int, map<int, multiset<int>>> m;
        rec(root, m, 0, 0);
        
        vector<int> row;
        
        for (auto i = m.begin(); i != m.end(); i++) {
            for (auto j = i->second.rbegin(); j != i->second.rend(); j++) {
                for (auto k = j->second.begin(); k != j->second.end(); k++) {
                    row.push_back(*k);
                }
            }
            
            res.push_back(row);
            row.clear();
        }
        
        return res;
    }
};