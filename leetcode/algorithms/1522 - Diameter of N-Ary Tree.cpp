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
    
    int dfs(Node* root, int& res) {
        if (!root) {
            return 0;
        }
        
        vector<int> v(2, 0);
        
        for (auto& i: root->children) {
            int next = dfs(i, res);
            if (next > v[1]) {
                swap(v[0], v[1]);
                v[1] = next;
            }
            else if (next > v[0]) {
                v[0] = next;
            }
        }
        
        res = max(res, v[0] + v[1]);
        return max(v[0], v[1]) + 1;
    }
    
public:
    int diameter(Node* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};