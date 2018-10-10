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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return construct(nums, 0, nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        
        int index = left;
        for (int i = left; i <= right; i++)
            if (nums[index] < nums[i])
                index = i;
        
        TreeNode* root = new TreeNode(nums[index]);
        root->left = construct(nums, left, index - 1);
        root->right = construct(nums, index + 1, right);
        return root;
    }
};