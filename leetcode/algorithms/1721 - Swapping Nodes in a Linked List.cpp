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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* first = head;
        ListNode* last = head;
        
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        
        cur = first->next;
        
        while (cur) {
            cur = cur->next;
            last = last->next;
        }
        
        swap(first->val, last->val);
        
        return head;
    }
};