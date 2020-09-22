class Solution {
    
    void backtrack(const int k , const int n, vector<int>& cur, int sum, int last, vector<vector<int>>& res) {
        if (k == 0) {
            if (sum == n) {
                res.push_back(cur);
            }
            return;
        }
        
        for (int i = last + 1; i <= 9; i++) {
            cur.push_back(i);
            backtrack(k - 1, n, cur, sum + i, i, res);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        
        vector<int> cur;
        backtrack(k, n, cur, 0, 0, res);
        
        return res;
    }
};