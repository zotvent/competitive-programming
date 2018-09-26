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
    ListNode* middleNode(ListNode* head) {
        int size = dfsCount(head);
        return dfs(head, size / 2);
    }

    int dfsCount(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }

    ListNode* dfs(ListNode* head, int left) {
        if (!left) return head;
        return dfs(head->next, left - 1);
    }
};