class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, start = 0, sum = 0;
        vector<bool> seen(1e4 + 1);
        
        for (int end = 0; end < nums.size(); end++) {
            while (seen[nums[end]]) {
                seen[nums[start]] = false;
                sum -= nums[start++];
            }
            
            sum += nums[end];
            seen[nums[end]] = true;
            res = max(res, sum);
        }
        
        return res;
    }
};