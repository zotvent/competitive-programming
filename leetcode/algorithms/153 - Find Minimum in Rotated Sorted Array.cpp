class Solution {
public:
    int findMin(vector<int>& nums) {        
        int l = 0;
        int r = nums.size() - 1;
        int max = nums[nums.size() - 1];
        
        while (l < r) {
            int m = (r - l) / 2 + l;
            
            if (nums[m] > max) l = m + 1;
            else r = m;
        }
                
        return nums[l];
    }
};