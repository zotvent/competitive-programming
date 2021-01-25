class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0, l = 0, r = nums.size() - 1, sum;
        sort(nums.begin(), nums.end());
        
        while (l < r) {
            sum = nums[l] + nums[r];
            
            if (sum == k) {
                res++;
                l++;
                r--;
            }
            else if (sum < k) l++;
            else r--;
        }
        
        return res;
    }
};