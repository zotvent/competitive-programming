/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* res = new Node(0);
        Node* cur = head;
        Node* iter = res;
        unordered_map<Node*, Node*> comp;
        
        while (cur) {
            iter->next = new Node(cur->val);
            comp[cur] = iter->next;
            iter = iter->next;
            cur = cur->next;
        }
        
        cur = head;
        iter = res->next;
        
        while (cur) {
            iter->random = comp[cur->random];
            iter = iter->next;
            cur = cur->next;
        }
        
        return res->next;
    }
};