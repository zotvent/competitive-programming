/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        
        Node* res = new Node(0);
        
        Node* prev = res;
        Node* cur;
        
        stack<Node*> s;
        s.push(head);
        
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            
            prev->next = cur;
            cur->prev = prev;
            
            if (cur->next) {
                s.push(cur->next);
            }
            
            if (cur->child) {
                s.push(cur->child);
                cur->child = NULL;
            }
            
            prev = cur;
        }
        
        res->next->prev = NULL;
        
        return res->next;
    }
};