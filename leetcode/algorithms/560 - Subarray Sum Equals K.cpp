class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += m[sum - k];
            m[sum]++;
        }
        
        return res;
    }
};