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
        Node* tail = res;
        
        int cnt = 0;
        
        unordered_map<Node*, int> original;
        unordered_map<int, Node*> copy;
        
        while (cur) {
            tail->next = new Node(cur->val);
            
            original[cur] = cnt;
            copy[cnt] = tail->next;
            
            tail = tail->next;
            cur = cur->next;
            cnt++;
        }
        
        cur = head;
        tail = res->next;
        cnt = 0;
        
        while (cur) {
            if (cur->random) {
                tail->random = copy[original[cur->random]];
            }
            cur = cur->next;
            tail = tail->next;
            cnt++;
        }
        
        return res->next;
    }
};