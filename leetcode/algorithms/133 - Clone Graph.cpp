/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> used;
        return dfs(node, used);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& used) {
        if (!node) return NULL;
        
        Node* cur = new Node();
        cur->val = node->val;
        
        used[node] = cur;
        
        for (auto i: node->neighbors) {
            if (used.count(i) == 0) {
                cur->neighbors.push_back(dfs(i, used));
            }
            else {
                cur->neighbors.push_back(used[i]);
            }
        }
        
        return cur;
    }
};