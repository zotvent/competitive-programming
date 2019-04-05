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
    vector<int> nextLargerNodes(ListNode* head) {        
        vector<int> res, stack;
        
        for (auto i = head; i != NULL; i = i->next) {
            while (!stack.empty() && res[stack.back()] < i->val) {
                res[stack.back()] = i->val;
                stack.pop_back();
            }
            
            stack.push_back(res.size());
            res.push_back(i->val);
        }
        
        for (auto i: stack) res[i] = 0;
        
        return res;
    }
};