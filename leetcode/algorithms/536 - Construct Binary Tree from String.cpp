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
    
    TreeNode* dfs(string& s, int& head) {
        string val = "";
        
        while (head < s.size() && (isdigit(s[head]) || s[head] == '-')) {
            val.push_back(s[head++]);
        }
        
        if (val.empty()) {
            return NULL;
        }
        
        TreeNode* res = new TreeNode(stoi(val));
        
        if (head < s.size() && s[head] == '(') {
            res->left = dfs(s, ++head);
            if (head < s.size() && s[head] == '(') {
                res->right = dfs(s, ++head);
                
            }
            head++;
        }
        else head++;
        
        return res;
    }
    
public:
    TreeNode* str2tree(string s) {
        int head = 0;
        return dfs(s, head);
    }
};