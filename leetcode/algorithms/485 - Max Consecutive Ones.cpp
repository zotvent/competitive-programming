class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;
        
        for (auto& i: nums) {
            if (i == 0) cur = 0;
            else cur++;
            res = max(res, cur);
        }
        
        return res;
    }
};