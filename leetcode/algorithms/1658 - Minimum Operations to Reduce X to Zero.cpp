class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = INT_MAX, sum = 0, left = 0;
        const int n = nums.size();
        
        for (auto& i: nums) {
            sum += i;
        }
        
        for (int right = 0; right < n; right++) {
            sum -= nums[right];
            
            while (sum < x && left <= right) {
                sum += nums[left++];
            }
            
            if (sum == x) {
                res = min(res, n - 1 - right + left);
            }
        }
        
        return (res == INT_MAX ? -1 : res);
    }
};