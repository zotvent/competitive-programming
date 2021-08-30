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
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = new Node(0);
        Node* tail = head;
        
        stack<Node*> s;
        
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            root->left = tail;
            tail->right = root;
            tail = tail->right;
            root = root->right;
        }
        
        tail->right = head->right;
        if (head->right) {
            head->right->left = tail;
        }
        
        return head->right;
    }
};