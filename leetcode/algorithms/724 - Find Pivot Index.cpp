class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        
        for (int i = 0; i < n; i++)
            right += nums[i];
        
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (left == right - nums[i]) {
                index = i;
                break;
            }
            left += nums[i];
            right -= nums[i];
        }   
        return index;
    }
};