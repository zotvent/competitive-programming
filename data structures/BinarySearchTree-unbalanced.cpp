template <typename T>
struct TreeNode {

    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T x) {
        val = x;
        left = NULL;
        right = NULL;
    }

};

TreeNode<int>* insert(TreeNode<int>* root, int x) {
    if (root) {
        if (x > root->val) {
            root->right = insert(root->right, x);
        }
        else if (x < root->val) {
            root->left = insert(root->left, x);
        }
    }
    else {
        root = new TreeNode<int>(x);
    }

    return root;
}
