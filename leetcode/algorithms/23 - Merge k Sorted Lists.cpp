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
        const int n = lists.size();
        unordered_map<int, ListNode*> m;
        int index;
        
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                m[i] = lists[i];
            }
        }
        
        while (!m.empty()) {
            index = -1;
            
            for (auto it = m.begin(); it != m.end(); it++) {
                if (index == -1 || (it->second)->val < m[index]->val) {
                    index = it->first;
                }
            }
            
            cur->next = m[index];
            cur = cur->next;
            
            m[index] = m[index]->next;
            
            if (!m[index]) {
                m.erase(index);
            }
        }
        
        return res->next;
    }
};