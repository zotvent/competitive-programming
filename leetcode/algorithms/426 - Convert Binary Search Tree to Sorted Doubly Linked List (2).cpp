/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    
    pair<Node*, Node*> inorder(Node* root) { // head (min), tail (max)
        if (!root) return {root, root};
        
        auto left = inorder(root->left);
        root->left = left.second;
        if (left.second) left.second->right = root;
        
        auto right = inorder(root->right);
        root->right = right.first;
        if (right.first) right.first->left = root;
        
        return {left.first ? left.first : root, right.second ? right.second : root};
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        
        auto res = inorder(root);
        auto head = res.first;
        auto tail = res.second;

        if (head) head->left = tail;
        if (tail) tail->right = head;
        
        return head;
    }
};