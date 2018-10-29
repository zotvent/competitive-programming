/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
    bool checkBST(Node* root) {
        if (!root) return true;

        bool leftIsLess = true;
        bool rightIsMore = true;

        if (root->left) leftIsLess = root->left->data < root->data;
        if (root->right) rightIsMore = root->data < root->right->data;

        Node* left = rightMost(root->left);
        Node* right = leftMost(root->right);

        if (left) leftIsLess = leftIsLess && left->data < root->data;
        if (right) rightIsMore = rightIsMore && root->data < right->data;

        return leftIsLess && rightIsMore && checkBST(root->left) && checkBST(root->right);
    }

    Node* leftMost(Node* root) {
        if (root) {
            while (root->left)
                root = root->left;
        }
        return root;
    }

    Node* rightMost(Node* root) {
        if (root) {
            while (root->right)
                root = root->right;
        }
        return root;
    }