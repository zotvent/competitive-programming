/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> s;

        s.push(root);
        while (!s.empty()) {
            Node* n = s.top();
            s.pop();

            if (n) {
                res.push_back(n->val);
                for (auto i: n->children)
                    s.push(i);
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};