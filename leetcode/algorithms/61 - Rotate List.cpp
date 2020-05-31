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
        if (!head || !head->next) {
            return head;
        }
        
        int size = 0;
        
        ListNode* cur = head;
        
        while (cur) {
            size++;
            cur = cur->next;
        }
        
        k %= size;
        cur = head;
        
        if (k == 0) {
            return head;
        }
        
        for (int i = 1; i < k; i++) {
            cur = cur->next;
        }
        
        ListNode* res = head;
        ListNode* prev = head;
        
        while (cur->next) {
            prev = res;
            cur = cur->next;
            res = res->next;
        }
        
        prev->next = NULL;
        cur->next = head;
        
        return res;
    }
};