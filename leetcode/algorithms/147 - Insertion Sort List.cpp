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
        ListNode* prev;
        ListNode* cur = head;
        ListNode* next;
        ListNode* nextIter;
        
        while (cur) {
            prev = res;
            next = res->next;
            
            while (next) {
                if (cur->val < next->val) {
                    break;
                }
                prev = next;
                next = next->next;
            }
            
            nextIter = cur->next;
            prev->next = cur;
            cur->next = next;
            cur = nextIter;
        }
        
        return res->next;
    }
};