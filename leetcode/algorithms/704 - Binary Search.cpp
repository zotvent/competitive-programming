class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            int x = nums[m];
            
            if (x == target) {
                return m;
            }
            else if (x < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return -1;
    }
};