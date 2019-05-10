class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        
        for (int i = 1, imin = res, imax = res; i < nums.size(); i++) {
            int tmp = imax;
            imax = max(max(imax * nums[i], imin * nums[i]), nums[i]);
            imin = min(min(tmp * nums[i], imin * nums[i]), nums[i]);
            res = max(res, imax);
        }
        
        return res;
    }
};