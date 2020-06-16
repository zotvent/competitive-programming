class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        
        int n = nums.size();
        
        vector<vector<int>> dp(n);
        vector<int> v;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            v.clear();
            
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && v.size() < dp[j].size()) {
                    v = dp[j];
                }
            }
            
            v.push_back(nums[i]);
            dp[i] = v;
        }
        
        vector<int> res;
        
        for (auto& i: dp) {
            if (res.size() < i.size()) {
                res = i;
            }
        }
        
        return res;
    }
};