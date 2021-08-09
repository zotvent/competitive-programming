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
        vector<int> level;
        queue<Node*> q;
        Node* cur;
        int size;
        
        if (root) q.push(root);
        
        while (!q.empty()) {
            size = q.size();
            
            for (; size > 0; size--) {
                cur = q.front();
                q.pop();
                
                level.push_back(cur->val);
                
                for (auto& next: cur->children) {
                    if (next) {
                        q.push(next);
                    }
                }
            }
            
            res.push_back(level);
            level.clear();
        }
        
        return res;
    }
};