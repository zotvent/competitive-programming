/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        
        Node* leftMost = root;
        Node* head;
        
        while (leftMost->left) {
            head = leftMost;
            
            while (head) {
                head->left->next = head->right;
                
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            leftMost = leftMost->left;
        }
        
        return root;
    }
};