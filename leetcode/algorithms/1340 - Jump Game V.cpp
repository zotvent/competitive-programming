class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = (int) arr.size();
        vector<int> dp(n, 1);
        
        set<pair<int, int>> s;
        int v, l, r;
        
        for (int i = 0; i < n; i++) {
            s.insert({arr[i], i});
        }
        
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            v = it->second;
            
            l = v - 1;
            while (l >= 0 && v - l <= d && arr[l] < arr[v]) {
                dp[l] = max(dp[l], dp[v] + 1);
                l--;
            }
            
            r = v + 1;
            while (r < n && r - v <= d && arr[r] < arr[v]) {
                dp[r] = max(dp[r], dp[v] + 1);
                r++;
            }
        }
        
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        
        return res;
    }
};