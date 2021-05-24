class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0, l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        
        while (l < r) {
            res += nums[r--] - nums[l++];
        }
        
        return res;
    }
};