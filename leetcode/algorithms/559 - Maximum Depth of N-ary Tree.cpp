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
    int maxDepth(Node* root) {
        int res = 0;
        dfs(root, res, 1);
        return res;
    }

    void dfs(Node* root, int& res, int cur) {
        if (root) {
            if (!root->children.size()) 
                res = max(res, cur);

            for (int i = 0; i < root->children.size(); i++)
                dfs(root->children[i], res, cur + 1);
        }
    }
};