class Solution {
    
    int rec(unordered_map<int, int>& memo, vector<int>& nums, int remain) {
        if (remain == 0) return 1;
        if (memo.count(remain) > 0) return memo[remain];
        
        int res = 0;
        
        for (auto& num: nums) {
            if (remain - num >= 0) {
                res += rec(memo, nums, remain - num);
            }
        }
        
        return memo[remain] = res;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return rec(memo, nums, target);
    }
};