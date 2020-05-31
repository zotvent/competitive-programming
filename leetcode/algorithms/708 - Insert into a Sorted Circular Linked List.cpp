/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* res = new Node(insertVal);
            res->next = res;
            return res;
        }
        
        Node* prev = head;
        Node* cur = head->next;
        bool toInsert = false;
        
        do {
            if (prev->val <= insertVal && insertVal <= cur->val) {
                toInsert = true;
            }
            else if (prev->val > cur->val) {
                if (insertVal <= cur->val || insertVal >= prev->val) {
                    toInsert = true;
                }
            }
            
            if (toInsert) {
                prev->next = new Node(insertVal, cur);
                return head;
            }
            
            prev = cur;
            cur = cur->next;
        } while (cur != head);
        
        prev->next = new Node(insertVal, cur);
        
        return head;
    }
};