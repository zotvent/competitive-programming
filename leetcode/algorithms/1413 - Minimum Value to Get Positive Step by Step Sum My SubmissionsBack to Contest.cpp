class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, mn = INT_MAX;
        
        for (auto& i: nums) {
            sum += i;
            mn = min(mn, sum);
        }
        
        return max(1, 1 - mn);
    }
};