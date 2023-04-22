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

    int getSize(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* res = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = res;
            res = head;
            head = next;
        }
        return res;
    }

public:
    bool isPalindrome(ListNode* head) {
        int size = getSize(head);
        ListNode* tail = head;
        for (int i = 0; i < (size + 1) / 2; i++) {
            tail = tail->next;
        }
        tail = reverse(tail);
        while (tail) {
            if (head->val != tail->val) {
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
