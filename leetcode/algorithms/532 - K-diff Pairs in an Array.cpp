class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        
        for (auto i: nums) {
            m[i]++;
        }
        
        for (auto& it: m) {            
            if (k == 0) {
                res += it.second > 1;
            }
            else if (m.count(it.first + k) > 0) {
                res++;
            }
        }
        
        return res;
    }
};