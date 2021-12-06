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
    
    struct Answer {
        bool res;
        int nodes;
        int minValue;
        int maxValue;
        
        Answer(bool res, int nodes, int minValue, int maxValue) {
            this->res = res;
            this->nodes = nodes;
            this->minValue = minValue;
            this->maxValue = maxValue;
        }
    };
    
    Answer dfs(TreeNode* root, int& ans, int minValue, int maxValue) {
        if (!root) {
            return Answer(true, 0, INT_MIN, INT_MAX);
        }
        
        Answer res = {true, 1, root->val, root->val};
        
        if (root->left) {
            auto left = dfs(root->left, ans, INT_MIN, INT_MAX);
            res.res &= left.res;
            res.nodes += left.nodes;
            res.minValue = min(res.minValue, left.minValue);
            res.maxValue = max(res.maxValue, left.maxValue);
            if (left.maxValue >= root->val) {
                res.res = false;
            }
        }
        
        if (root->right) {
            auto right = dfs(root->right, ans, INT_MIN, INT_MAX);
            res.res &= right.res;
            res.nodes += right.nodes;
            res.minValue = min(res.minValue, right.minValue);
            res.maxValue = max(res.maxValue, right.maxValue);
            if (right.minValue <= root->val) {
                res.res = false;
            }
        }
        
        if (res.res) {
            ans = max(ans, res.nodes);
        }
        
        return res;
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res, INT_MIN, INT_MAX);
        return res;
    }
};