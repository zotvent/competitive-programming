class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        
        return nums[l];
    }
};