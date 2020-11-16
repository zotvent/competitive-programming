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
    
    ListNode* reverse(ListNode* root) {
        ListNode* res = NULL;
        ListNode* next = NULL;
        
        while (root) {
            next = root->next;
            root->next = res;
            res = root;
            root = next;
        }
        
        return res;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);
        
        ListNode* res = new ListNode();
        ListNode* cur = res;
        int carry = 0;
        
        while (r1 || r2 || carry > 0) {
            if (r1) {
                carry += r1->val;
                r1 = r1->next;
            }
            
            if (r2) {
                carry += r2->val;
                r2 = r2->next;
            }
            
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;
        }
        
        cur = res->next;
        res->next = NULL;
        res = cur;
        res = reverse(res);
        
        return res;
    }
};