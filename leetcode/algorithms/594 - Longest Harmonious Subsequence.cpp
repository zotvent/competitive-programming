class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        
        for (auto& i: nums) {
            m[i]++;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (m.count(it->first + 1) > 0) {
                res = max(res, it->second + m[it->first + 1]);
            }
        }
        
        return res;
    }
};