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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            
            if (fast) {
                fast = fast->next;
            }
        }
        
        bool res = true;
        
        ListNode* reversedHalf = reverse(slow);
        
        slow = head;
        fast = reversedHalf;
        
        while (reversedHalf) {
            if (reversedHalf->val != head->val) {
                res = false;
                break;
            }
            head = head->next;
            reversedHalf = reversedHalf->next;
        }
        
        reverse(fast);
        
        return res;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};