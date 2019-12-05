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
        ListNode* res = new ListNode(0);
        ListNode* slow = res;
        ListNode* fast = res;
        
        slow->next = head;
        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return res->next;
    }
};