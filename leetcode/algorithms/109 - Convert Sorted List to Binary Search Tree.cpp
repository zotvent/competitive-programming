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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    ListNode* head;
    
    TreeNode* reverseInOrder(int n) {
        if (n == 0) {
            return NULL;
        }
        
        TreeNode* left = reverseInOrder(n / 2);
        TreeNode* res = new TreeNode(head->val);
        head = head->next;
        res->left = left;
        res->right = reverseInOrder(n - n / 2 - 1);
        
        return res;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        ListNode* cur = head;
        int size = 0;
        
        while (cur) {
            size++;
            cur = cur->next;
        }
        
        return reverseInOrder(size);
    }
};