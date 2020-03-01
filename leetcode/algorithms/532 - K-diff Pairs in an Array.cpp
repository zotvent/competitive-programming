class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int res = 0;
        unordered_map<int, int> m;
        
        for (auto i: nums) m[i]++;
        
        for (auto it = m.begin(); it != m.end(); it++) {            
            if (k == 0) {
                res += it->second > 1;
            }
            else if (m.count(it->first + k) > 0) {
                res++;
            }
        }
        
        return res;
    }
};