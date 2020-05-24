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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        return dfs(head, n, cnt);
    }
    
    ListNode* dfs(ListNode* head, int n, int& cnt) {
        if (!head) {
            return NULL;
        }
        
        head->next = dfs(head->next, n, cnt);
        cnt++;
        
        return (cnt == n ? head->next : head);
    }
};