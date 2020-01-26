/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            ListNode* next = head->next;
            swap(head, next);
            
            next->next = swapPairs(head->next);
            head->next = next;
            
            return head;
        }
        else return head;
    }
};