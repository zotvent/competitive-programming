class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = -1;
        
        int sum = 0;        
        int l = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            
            if (sum >= s) {
                while (l < r && sum - nums[l] >= s) {
                    sum -= nums[l++];
                }
                
                if (res == -1) res = r - l + 1;
                else res = min(res, r - l + 1);
            }
        }
        
        return (res == -1 ? 0 : res);
    }
};