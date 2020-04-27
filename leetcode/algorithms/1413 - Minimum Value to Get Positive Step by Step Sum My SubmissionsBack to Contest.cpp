class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = nums[0];
        int mn = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            mn = min(mn, sum);
        }
        
        return max(1, 1 - mn);
    }
};