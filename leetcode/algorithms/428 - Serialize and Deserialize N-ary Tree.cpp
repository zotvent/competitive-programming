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

class Codec {
    
    Node* deserialize(string& data, int start, int end) {
        // printf("[%d, %d]\n", start, end);
        
        if (start > end) {
            return NULL;
        }
        
        int i = start + 1;
        
        while (isdigit(data[i])) {
            i++;
        }
        
        Node* res = new Node(stoi(data.substr(start + 1, i - start - 1)));
        Node* child;
        
        // if node has children
        if (data[i] == ',') {
            int open = 0;
            int close = 0;
            int left = i + 1;
            
            for (int cur = i + 1; cur < end; cur++) {
                if (data[cur] == '[') {
                    open++;
                }
                else if (data[cur] == ']') {
                    close++;
                }
                
                if (open == close) {
                    child = deserialize(data, left, cur);
                    if (child) {
                        res->children.push_back(child);
                    }
                    
                    left = cur + 1;
                    if (left < end && data[left] == ',') {
                        left++;
                    }
                }
            }
        }
        
        return res;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) {
            return "";
        }
        
        string res = "[";
        
        res += to_string(root->val);
        
        for (auto& ch: root->children) {
            if (ch) {
                res.push_back(',');
                res += serialize(ch);
            }
        }
        
        res.push_back(']');
        
        return res;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        // printf("data = %s\n", data.c_str());
        return deserialize(data, 0, data.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));