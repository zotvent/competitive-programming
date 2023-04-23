class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (binary_search(nums.begin(), nums.end(), target)) {
            int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            return {l, r - 1};
        }
        return {-1, -1};
    }
};
