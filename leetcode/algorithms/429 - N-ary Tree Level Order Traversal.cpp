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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        queue<Node*> q;
        q.push(root);
        
        Node* v;
        int size;
        vector<int> level;
        
        while (!q.empty()) {
            size = q.size();
            
            while (size) {
                v = q.front();
                q.pop();
                
                if (v) {
                    level.push_back(v->val);
                    
                    for (auto& ch: v->children) {
                        if (ch) {
                            q.push(ch);
                        }
                    }
                }
                
                size--;
            }
            
            if (!level.empty()) {
                res.push_back(level);
            }
            
            level.clear();
        }
        
        return res;
    }
};