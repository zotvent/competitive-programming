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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<TreeNode*> res;
        
        unordered_map<string, vector<TreeNode*>> m;
        dfs(root, m);
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                res.push_back(it->second[0]);
            }
        }
        
        return res;
    }
    
    string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>>& m) {
        if (!root) {
            return "";
        }
        
        string left = dfs(root->left, m);
        string right = dfs(root->right, m);
        
        string res = "({" + left + "},";
        res += to_string(root->val) + ",";
        res += "{" + right + "})";
        
        m[res].push_back(root);
        
        return res;
    }
};