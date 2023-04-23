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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* cur = res;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        
        for (auto& i: lists) {
            if (i) {
                q.push({i->val, i});
            }
        }
        
        while (!q.empty()) {
            auto top = q.top();
            q.pop();

            cur->next = top.second;
            cur = cur->next;
            if (top.second->next) {
                q.push({top.second->next->val, top.second->next});
            }
        }
        
        return res->next;
    }
};
