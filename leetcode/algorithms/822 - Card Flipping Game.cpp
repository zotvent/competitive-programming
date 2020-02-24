class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int mn = INT_MAX;
        int res;
        
        int n = (int) fronts.size();
        unordered_set<int> forbidden;
        
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                forbidden.insert(fronts[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (forbidden.count(fronts[i]) > 0 && forbidden.count(backs[i]) == 0 && mn > backs[i]) {
                mn = backs[i];
                res = i;
            }
            else if (forbidden.count(backs[i]) > 0 && forbidden.count(fronts[i]) == 0 && mn > fronts[i]) {
                mn = fronts[i];
                res = i;
            }
            else if (forbidden.count(fronts[i]) == 0 && forbidden.count(backs[i]) == 0 && mn > min(backs[i], fronts[i])) {
                mn = min(backs[i], fronts[i]);
                res = i;
            }
        }
        
        if (mn == INT_MAX) res = 0;
        else res = mn;
        
        return res;
    }
};