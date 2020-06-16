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
private:
    Node* leftMost;
    Node* prev;
    
    void process(Node* root) {
        if (!root) {
            return;
        }
        
        if (prev) {
            prev->next = root;
        }
        else {
            leftMost = root;
        }
        
        prev = root;
    }
    
public:
    Node* connect(Node* root) {
        leftMost = root;
        Node* cur;
        
        while (leftMost) {
            cur = leftMost;
            leftMost = NULL;
            prev = NULL;
            
            while (cur) {
                process(cur->left);
                process(cur->right);
                cur = cur->next;
            }
        }
        
        return root;
    }
};