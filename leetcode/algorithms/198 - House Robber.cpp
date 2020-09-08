class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        int prev = 0;
        int tmp;
        
        for (auto& i: nums) {
            tmp = res;
            res = max(i + prev, res);
            prev = tmp;
        }
        
        return res;
    }
};