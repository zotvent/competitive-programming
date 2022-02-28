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
    
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        
        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        
        if (left) cur->next = left;
        else cur->next = right;

        return res->next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = NULL;
        
        while (head && head->next) {
            midPrev = midPrev ? midPrev->next : head;
            head = head->next->next;
        }
        
        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        
        return mid;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
};