class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        bool flag = false;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) flag = true;
            if (flag) {
                mn = min(mn, nums[i]);
            }
        }
        
        flag = false;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) flag = true;
            if (flag) {
                mx = max(mx, nums[i]);
            }
        }
        
        int l, r;
        
        for (l = 0; l < nums.size(); l++) {
            if (mn < nums[l]) break;
        }
        
        for (r = nums.size() - 1; r >= 0; r--) {
            if (mx > nums[r]) break;
        }
        
        return (r - l >= 0 ? r - l + 1 : 0);
    }
};