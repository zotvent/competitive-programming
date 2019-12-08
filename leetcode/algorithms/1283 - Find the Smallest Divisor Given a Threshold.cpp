class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {        
        int l = 1;
        int r = (int) 1e6;
        int m, sum;
        
        while (l < r) {
            m = l + (r - l) / 2;
            sum = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                sum += (nums[i] + m - 1) / m;
            }
            
            if (sum > threshold) l = m + 1;
            else r = m;
        }
        
        return l;
    }
};