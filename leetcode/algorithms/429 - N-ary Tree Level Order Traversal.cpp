/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>>();

        vector<vector<int>> res;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node* v = q.front();
                q.pop();
                level.push_back(v->val);
                for (auto c : v->children)
                    q.push(c);
            }

            res.push_back(level);
        }

        return res;
    }
};