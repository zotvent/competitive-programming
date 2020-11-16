class Solution {
    
    void backtrack(vector<int>& cur, unordered_map<int, int>& cnt, vector<vector<int>>& res, const int n) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second > 0) {
                cur.push_back(it->first);
                it->second--;
                backtrack(cur, cnt, res, n);
                
                cur.pop_back();
                it->second++;
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> cnt;
        vector<int> cur;
        const int n = nums.size();
        
        for (auto& i: nums) {
            cnt[i]++;
        }
        
        backtrack(cur, cnt, res, n);
        return res;
    }
};