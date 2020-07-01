/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        
        queue<Node*> s;
        int size;
        Node* v;
        
        if (root) {
            s.push(root);
        }
        
        while (!s.empty()) {
            size = s.size();
            
            for (int i = 0; i < size; i++) {
                v = s.front();
                s.pop();
                
                for (auto& ch: v->children) {
                    if (ch) {
                        s.push(ch);
                    }
                }
            }
            
            res++;
        }
        
        return res;
    }
};