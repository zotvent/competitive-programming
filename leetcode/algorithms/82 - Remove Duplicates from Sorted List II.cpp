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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* prev = res;
        
        while (head) {
            if (head->next && head->val == head->next->val) {
                int val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
            }
            else {
                prev->next = head;
                head = head->next;
                prev = prev->next;
                prev->next = NULL;
            }
        }
        
        return res->next;
    }
};