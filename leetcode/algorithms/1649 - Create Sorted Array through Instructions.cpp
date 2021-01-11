class Solution {
    
    int get(vector<int>& tree, int x) {
        int res = 0;
        
        while (x > 0) {
            res += tree[x];
            x -= x & -x;
        }
        
        return res;
    }
    
    void update(vector<int>& tree, int x) {
        const int n = tree.size();
        while (x < n) {
            tree[x]++;
            x += x & -x;
        }
    }
    
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> tree(1e5 + 1);
        int res = 0, mod = 1e9 + 7;
        
        for (int i = 0; i < instructions.size(); i++) {
            res = (res + min(get(tree, instructions[i] - 1), i - get(tree, instructions[i]))) % mod;
            update(tree, instructions[i]);
        }
        
        return res;
    }
};