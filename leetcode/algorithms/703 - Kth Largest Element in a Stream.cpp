class KthLargest {
    
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        int val;
        int cnt;
        
        TreeNode(int val) {
            this->val = val;
            left = right = NULL;
            cnt = 1;
        }
    };
    
    TreeNode* root;
    int k;
    
    void build(vector<int>& nums) {
        for (auto& i: nums) {
            root = add(root, i);
        }
    }
    
    TreeNode* add(TreeNode* root, int x) {
        if (!root) {
            return new TreeNode(x);
        }
        
        if (x <= root->val) {
            root->left = add(root->left, x);
        }
        else {
            root->right = add(root->right, x);
        }
        
        root->cnt++;
        
        return root;
    }
    
    int searchKth(TreeNode* root, int k) {
        int cur = (root->right ? (root->right)->cnt : 0) + 1;
        
        if (cur == k) {
            return root->val;
        }
        
        if (k < cur) {
            return searchKth(root->right, k);
        }
        else {
            return searchKth(root->left, k - cur);
        }
    }
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        root = NULL;
        build(nums);
    }
    
    int add(int val) {
        root = add(root, val);
        return searchKth(root, k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */