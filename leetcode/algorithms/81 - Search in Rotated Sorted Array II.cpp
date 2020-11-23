class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            if (nums[m] == target) {
                return true;
            }
            else if (nums[l] == nums[m] && nums[m] == nums[r]) {
                l++;
                r--;
            }
            else if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            }
            else {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        
        return false;
    }
};