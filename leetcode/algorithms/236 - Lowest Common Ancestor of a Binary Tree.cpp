/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        
        stack<TreeNode*> s;
        s.push(root);
        parent[root] = NULL;
        
        TreeNode* v;
        
        while (!s.empty()) {
            v = s.top();
            s.pop();
            
            if (v) {
                if (v->left) {
                    parent[v->left] = v;
                    s.push(v->left);
                }
                if (v->right) {
                    parent[v->right] = v;
                    s.push(v->right);
                }
            }
        }
        
        unordered_set<TreeNode*> path;
        
        while (p) {
            path.insert(p);
            p = parent[p];
        }
        
        while (path.count(q) == 0) {
            q = parent[q];
        }
        
        return q;
    }
};