class Solution {
    
    struct TrieNode {
        vector<TrieNode*> children;
        
        TrieNode() {
            children.assign(2, NULL);
        }
    };
    
    TrieNode* buildTrie(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        
        TrieNode* cur;
        int index;
        
        for(auto& num: nums) {
            cur = root;
            
            for (int i = 31; i >= 0; i--) {
                index = ((num >> i) & 1);
                
                if (!cur->children[index]) {
                    cur->children[index] = new TrieNode();
                }
                
                cur = cur->children[index];
            }
        }
        
        return root;
    }
    
    int helper(TrieNode* root, int num) {
        int res = 0;
        
        int complement;
        
        for (int i = 31; i >= 0; i--) {
            complement = ((num >> i) & 1) ? 0 : 1;
            
            if (root->children[complement]) {
                res <<= 1;
                res |= 1;
                root = root->children[complement];
            }
            else {
                res <<= 1;
                root = root->children[complement ? 0 : 1];
            }
        }
        
        return res;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;

        TrieNode* root = buildTrie(nums);
        
        for (auto& i: nums) {
            res = max(res, helper(root, i));
        }
        
        return res;
    }
};