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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* cur;
        ListNode* prev;
        
        while (head) {
            prev = res;
            cur = res->next;
            
            while (prev) {
                if (!cur) {
                    prev->next = new ListNode(head->val);
                    break;
                }
                
                if (cur->val > head->val) {
                    prev->next = new ListNode(head->val);
                    prev->next->next = cur;
                    break;
                }
                
                prev = cur;
                cur = cur->next;
            }
            
            head = head->next;
        }
        
        return res->next;
    }
};