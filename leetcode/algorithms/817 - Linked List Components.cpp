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
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        set<int> s;
        
        for (int i = 0; i < G.size(); i++)
            s.insert(G[i]);
        
        while (head) {
            if (s.count(head->val) && (head->next == NULL || !s.count(head->next->val)))
                res++;
            head = head->next;
        }
        
        return res;
    }
};