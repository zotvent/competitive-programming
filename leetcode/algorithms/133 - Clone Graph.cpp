/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return node;
        
        Node* res = new Node(node->val);
        m[node] = res;
        
        for (auto& to: node->neighbors) {
            if (m.count(to) == 0) {
                dfs(to, m);
            }
            res->neighbors.push_back(m[to]);
        }
        
        return res;
    }
    
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }
};