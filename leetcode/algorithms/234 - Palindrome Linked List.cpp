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
    bool isPalindrome(ListNode* head) {
        ListNode* reverse = NULL;
        ListNode* copy = head;
        
        while (copy) {
            ListNode* node = new ListNode(copy->val);
            
            if (reverse) {    
                node->next = reverse;
            }
            
            reverse = node;
            copy = copy->next;
        }
        
        bool equals = true;
        
        while (reverse && head) {
            if (reverse->val != head->val) {
                equals = false;
                break;
            }
            
            reverse = reverse->next;
            head = head->next;
        }
        
        return equals;
    }
};