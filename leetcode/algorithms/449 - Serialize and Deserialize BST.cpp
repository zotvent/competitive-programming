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
        if (!root) {
            return;
        }
        
        doSerialize(root->left, res);
        doSerialize(root->right, res);
        res += to_string(root->val);
        res.push_back(',');
    }
    
    vector<int> parse(string& data) {
        vector<int> res;
        string cur = "";
        
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                res.push_back(stoi(cur));
                cur.clear();
            }
            else {
                cur.push_back(data[i]);
            }
        }
        
        return res;
    }
    
    TreeNode* doDeserialize(vector<int>& nums, int lo, int hi) {
        if (nums.empty()) {
            return NULL;
        }
        
        int val = nums.back();
        
        if (val < lo || val > hi) {
            return NULL;
        }
        
        nums.pop_back();
        
        TreeNode* root = new TreeNode(val);
        root->right = doDeserialize(nums, val, hi);
        root->left = doDeserialize(nums, lo, val);
        
        return root;
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
        vector<int> nums = parse(data);
        return doDeserialize(nums, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;