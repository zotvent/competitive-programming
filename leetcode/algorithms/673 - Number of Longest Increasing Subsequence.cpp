class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lengths(n, 0), counts(n, 1);
        
        for (int r = 0; r < n; r++) {
            for (int l = 0; l < r; l++) {
                if (nums[l] < nums[r]) {
                    if (lengths[l] >= lengths[r]) {
                        lengths[r] = lengths[l] + 1;
                        counts[r] = counts[l];
                    }
                    else if (lengths[l] + 1 == lengths[r]) {
                        counts[r] += counts[l];
                    }
                }
            }
        }
        
        int res = 0, longest = 0;
        
        for (auto& i: lengths) {
            longest = max(longest, i);
        }
        
        for (int i = 0; i < n; i++) {
            if (lengths[i] == longest) {
                res += counts[i];
            }
        }
        
        return res;
    }
};