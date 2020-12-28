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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* cur = res;
        ListNode* next = NULL;
        
        while (head) {
            next = head->next;
            
            if (next) {
                head->next = next->next;
                next->next = head;
                cur->next = next;
                cur = cur->next;
            }
            else {
                cur->next = head;
            }
            
            cur = cur->next;
            head = head->next;
        }
        
        return res->next;
    }
};