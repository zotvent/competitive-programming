/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    TreeNode* recovered;
    
    void dfs(TreeNode* root, int value) {
        if (root) {
            root->val = value;
            dfs(root->left, 2 * value + 1);
            dfs(root->right, 2 * value + 2);
        }
    }
    
    bool find(TreeNode* root, int value) {
        if (!root) {
            return false;
        }
        
        if (root->val == value) {
            return true;
        }
        else {
            return find(root->left, value) || find(root->right, value);
        }
    }
    
public:
    FindElements(TreeNode* root) {
        recovered = root;
        
        if (recovered) {
            recovered->val = 0;
            dfs(root->left, 1);
            dfs(root->right, 2);
        }
    }
    
    bool find(int target) {
        return find(recovered, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */