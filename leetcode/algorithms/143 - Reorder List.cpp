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
    
    ListNode* reverse(ListNode* head) {
        ListNode* tail = NULL;
        ListNode* next;
        
        while (head) {
            next = head->next;
            head->next = tail;
            tail = head;
            head = next;
        }
        
        return tail;
    }
    
public:
    void reorderList(ListNode* head) {
        ListNode* res = head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = reverse(slow);
        ListNode* next;
        ListNode* secondNext;
        
        while (second && second->next) {
            next = head->next;
            secondNext = second->next;
            
            head->next = second;
            head->next->next = next;
            
            second = secondNext;
            head = next;
        }
    }
};