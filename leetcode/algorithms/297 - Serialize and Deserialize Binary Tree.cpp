/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
    void doSerialize(TreeNode* root, string& res) {
        if (!res.empty()) {
            res.push_back(',');
        }
        
        if (!root) {
            res += "null";
            return;
        }
        
        res += to_string(root->val);
        doSerialize(root->left, res);
        doSerialize(root->right, res);
    }
    
    TreeNode* doDeserialize(queue<string>& q) {
        if (q.empty()) {
            return NULL;
        }
        
        string front = q.front();
        q.pop();
        
        if (front == "null") {
            return NULL;
        }
        
        TreeNode* res = new TreeNode(stoi(front));
        res->left = doDeserialize(q);
        res->right = doDeserialize(q);
        
        return res;
    }
    
    queue<string> split(string& data) {
        queue<string> q;
        int start = 0;
        
        for (int i = 0; i <= data.size(); i++) {
            if (data[i] == ',' || i == data.size()) {
                q.push(data.substr(start, i - start));
                start = i + 1;
            }
        }
        
        return q;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        doSerialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = split(data);
        return doDeserialize(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));