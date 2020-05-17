class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int res = -1;
        
        int sum = 0;
        int left = 0;
        
        for (auto i: nums) {
            sum += i;
        }
               
        for (int i = 0; i < nums.size(); i++) {
            if (left == sum - left - nums[i]) {
                res = i;
                break;
            }
            left += nums[i];
        }
        
        return res;
    }
};