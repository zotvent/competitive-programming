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
        ListNode* cur = res;
        ListNode* prev = res;
        
        while (head) {
            if (cur != res && head->val == cur->val) {
                while (head && head->val == cur->val) {
                    head = head->next;
                }
                
                cur = prev;
                prev->next = NULL;
            }
            else {
                cur->next = head;
                head = head->next;
                prev = cur;
                cur = cur->next;
            }
        }
        
        return res->next;
    }
};