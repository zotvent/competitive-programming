class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int n = nums.size();
        vector<int> mins = nums;
        int mx = nums[0];
        
        for (int i = n - 2; i >= 0; i--) {
            mins[i] = min(mins[i], mins[i + 1]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (mx <= mins[i + 1]) {
                return i + 1;
            }
            mx = max(mx, nums[i]);
        }
        
        return -1;
    }
};