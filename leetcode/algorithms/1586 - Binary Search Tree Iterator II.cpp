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
class BSTIterator {
    vector<int> nums;
    int head;
    
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            nums.push_back(root->val);
            root = root->right;
        }
        
        head = -1;
    }
    
    bool hasNext() {
        return head < (int) nums.size() - 1;
    }
    
    int next() {
        return nums[++head];
    }
    
    bool hasPrev() {
        return head > 0;
    }
    
    int prev() {
        return nums[--head];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */