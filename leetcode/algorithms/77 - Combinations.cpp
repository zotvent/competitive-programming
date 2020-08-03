class Solution {
    
    void backtrack(int n, int k, vector<vector<int>>& res, vector<int>& cur, int prev) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        if (prev == n) {
            return;
        }
        
        for (int i = prev + 1; i <= n; i++) {
            cur.push_back(i);
            backtrack(n, k, res, cur, i);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        
        backtrack(n, k, res, cur, 0);
        
        return res;
    }
};