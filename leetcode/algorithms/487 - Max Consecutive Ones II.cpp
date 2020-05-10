class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        
        int zero = -1;
        int left = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero != -1) {
                    left = zero + 1;
                }
                zero = i;
            }
            
            res = max(res, i - left + 1);
        }
        
        return res;
    }
};