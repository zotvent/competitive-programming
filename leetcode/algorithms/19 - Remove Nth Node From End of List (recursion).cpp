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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int left = rec(head, n);
        return (left != 0) ? head : head->next;
    }
    
    int rec(ListNode* head, int n) {
        if (!head) return n;
        
        int left = rec(head->next, n);
        
        if (left == 0) {
            ListNode* next = head->next;
            if (next) {
                head->next = next->next;
            }
        }
        
        return left - 1;
    }
};