class Solution {
    
    int sum(vector<int>& tree, int v, int tl, int tr, int l, int r) {
        if (tr < l || r < tl) return 0;
        if (l <= tl && tr <= r) return tree[v];
        
        int tm = tl + (tr - tl) / 2;
        return sum(tree, 2*v, tl, tm, l, r) + sum(tree, 2*v + 1, tm + 1, tr, l, r);
    }
    
    void update(vector<int>& tree, int v, int tl, int tr, int index) {
        if (tl == tr) {
            tree[v]++;
            return;
        }
        
        int tm = tl + (tr - tl) / 2;
        if (index <= tm) update(tree, 2*v, tl, tm, index);
        else update(tree, 2*v + 1, tm + 1, tr, index);
        tree[v] = tree[2*v] + tree[2*v + 1];
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int shift = (int) 1e4;
        const int size = 2 * shift, n = nums.size();
        vector<int> res(n), tree(4 * size);
        
        for (int i = n - 1; i >= 0; i--) {
            res[i] = sum(tree, 1, 1, 2*shift + 1, 1, nums[i] + shift);
            update(tree, 1, 1, 2*shift + 1, nums[i] + 1 + shift);
        }
        
        return res;
    }
};