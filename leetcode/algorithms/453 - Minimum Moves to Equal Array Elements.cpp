class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, mn = INT_MAX;
        
        for (auto& i: nums) {
            mn = min(mn, i);
        }
        
        for (auto& i: nums) {
            res += i - mn;
        }
        
        return res;
    }
};