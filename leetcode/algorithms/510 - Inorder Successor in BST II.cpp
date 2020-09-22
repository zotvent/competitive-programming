/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) {
            return node;
        }
        
        if (node->right) {
            node = node->right;
            
            while (node->left) {
                node = node->left;
            }
            
            return node;
        }
        else {
            int target = node->val;
            
            while (node && node->val <= target) {
                node = node->parent;
            }
            
            if (node && node->val > target) {
                return node;
            }
            else {
                return NULL;
            }
        }
    }
};