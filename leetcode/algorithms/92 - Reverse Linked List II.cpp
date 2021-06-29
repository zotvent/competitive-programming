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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* res = new ListNode(0);
        res->next = head;
        
        ListNode* prev = res;
        
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        
        ListNode* start = prev->next;
        ListNode* then = start->next;
        
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }
        
        return res->next;
    }
};