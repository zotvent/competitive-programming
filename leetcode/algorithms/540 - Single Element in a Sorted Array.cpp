class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        
        int l = 0;
        int r = (int) nums.size() - 1;
        int m;
        
        while (l < r) {
            m = l + (r - l) / 2;
            if (m % 2 == 1) m--;
            
            if (nums[m] == nums[m + 1]) l = m + 2;
            else r = m;
        }
        
        return nums[l];
    }
};