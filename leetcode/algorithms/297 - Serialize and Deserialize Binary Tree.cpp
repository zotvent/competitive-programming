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
private:
    TreeNode* dfs(string& data, int l, int r) {
        if (l > r) {
            return NULL;
        }
        
        int open = 0;
        int close = 0;
        int head = l;
        
        do {
            if (data[head] == '{') {
                open++;
            }
            else if (data[head] == '}') {
                close++;
            }
            
            head++;
        } while (open != close && head < r);
        
        int leftComma = head;
        
        head++;
        while (data[head] != ',') {
            head++;
        }
        
        int rightComma = head;
        
        TreeNode* root = new TreeNode(stoi(data.substr(leftComma + 1, rightComma - leftComma - 1)));
        
        root->left = dfs(data, l + 1, leftComma - 2);
        root->right = dfs(data, rightComma + 2, r - 1);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "{}";
        }
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        string res = "{";
        res += left + ",";
        res += to_string(root->val);
        res += "," + right + "}";
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        return dfs(data, 1, data.size() - 2);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));