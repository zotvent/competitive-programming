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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* node = res;
        
        while (l1 || l2) {
            if (!l1) {
                node->next = l2;
                break;
            }
            
            if (!l2) {
                node->next = l1;
                break;
            }
            
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            
            node->next->next = NULL;
            node = node->next;
        }
        
        return res->next;
    }
};