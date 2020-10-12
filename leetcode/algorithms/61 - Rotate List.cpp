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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        ListNode* oldTail = head;
        int n;
        
        for (n = 1; oldTail->next; n++) {
            oldTail = oldTail->next;
        }
        oldTail->next = head;
        
        ListNode* newTail = head;
        
        for (int i = 0; i < n - k % n - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* res = newTail->next;
        newTail->next = NULL;
        
        return res;
    }
};