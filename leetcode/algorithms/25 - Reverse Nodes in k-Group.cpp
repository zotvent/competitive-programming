/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    int getSize(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
    
    ListNode* reverse(ListNode* prev, ListNode* node, int k) {
        ListNode* tail = node;
        ListNode* next;
        
        for (int i = 0; i < k; i++) {
            next = node->next;
            node->next = prev->next;
            prev->next = node;
            node = next;
        }
        tail->next = node;
        
        return tail;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode();
        ListNode* prev = res;
        ListNode* next;
        int size = getSize(head);
        
        for (int i = 0; i <= size - k; i += k) {
            next = reverse(prev, head, k);
            prev = next;
            head = next->next;
        }
        
        return res->next;
    }
};