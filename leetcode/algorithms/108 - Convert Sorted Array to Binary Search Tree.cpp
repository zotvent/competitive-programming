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
    
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        }
        
        int m = l + (r - l) / 2;
        TreeNode* res = new TreeNode(nums[m]);
        res->left = build(nums, l, m - 1);
        res->right = build(nums, m + 1, r);
        
        return res;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};