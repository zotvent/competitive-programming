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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result, count;
        average(root, 0, result, count);
        for (int i = 0; i < result.size(); i++)
            result[i] /= count[i];
        return result;
    }
    
    void average(TreeNode* node, int depth, vector<double> &sum, vector<double> &count) {
        if (node == NULL) return;
        
        if (sum.size() == depth) {
            sum.push_back(node->val);
            count.push_back(1);
        }
        else {
            sum[depth] += node->val;
            count[depth]++;
        }
        average(node->left, depth+1, sum, count);
        average(node->right, depth+1, sum, count);
    }
};