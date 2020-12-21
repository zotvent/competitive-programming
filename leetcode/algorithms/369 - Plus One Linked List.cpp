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
    
    int rec(ListNode* head, int carry) {
        if (!head) {
            return carry;
        }
        
        carry = rec(head->next, carry);
        int val = head->val;
        
        head->val = (val + carry) % 10;
        carry = (val + carry) / 10;
        
        return carry;
    }
    
public:
    ListNode* plusOne(ListNode* head) {
        int carry = rec(head, 1);
        ListNode* res = new ListNode(carry);
        res->next = head;
        
        return (carry > 0 ? res : head);
    }
};