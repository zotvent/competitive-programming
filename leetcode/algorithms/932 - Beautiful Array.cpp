class Solution {
    
    vector<int> rec(int n, unordered_map<int, vector<int>>& memo) {
        if (memo.count(n) > 0) {
            return memo[n];
        }
        
        vector<int> res(n);
        
        if (n == 1) {
            res[0] = 1;
        }
        else {
            int head = 0;
            for (auto& odd: rec((n + 1) / 2, memo)) {
                res[head++] = 2 * odd - 1;
            }
            for (auto& even: rec(n / 2, memo)) {
                res[head++] = 2 * even;
            }
        }
        
        return memo[n] = res;
    }
    
public:
    vector<int> beautifulArray(int n) {
        unordered_map<int, vector<int>> memo;
        return rec(n, memo);
    }
};