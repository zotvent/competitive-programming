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
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> s;

        s.push(root);
        while (!s.empty()) {
            Node* v = s.top();
            s.pop();

            if (v) {
                res.push_back(v->val);
                for (int i = v->children.size() - 1; i >= 0; i--)
                    s.push(v->children[i]);
            }
        }

        return res;
    }
};