class Solution {
    
    int count(vector<int>& nums, int bound) {
        int res = 0, sum = 0;
        for (auto& i: nums) {
            if (i <= bound) sum++;
            else sum = 0;
            res += sum;
        }
        return res;
    }
    
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
};