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
    
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> preprocess(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> res;
        
        for (auto& i: lists) {
            if (i) {
                res.push({i->val, i});
            }
        }
        
        return res;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        ListNode* next;
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> mins = preprocess(lists);
        pair<int, ListNode*> cur;
        
        while (!mins.empty()) {
            cur = mins.top();
            mins.pop();
            
            head->next = cur.second;
            next = cur.second->next;
            if (next) {
                mins.push({next->val, next});
            }
            head = head->next;
        }
        
        return res->next;
    }
};