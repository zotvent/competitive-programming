class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> rightest;
        for (int i = 0; i < nums.size(); i++) {
            if (rightest.find(nums[i]) != rightest.end()) {
                int r = rightest[nums[i]];
                if (i - r <= k) return true;
                rightest[nums[i]] = max(rightest[nums[i]], i);
            }
            else rightest[nums[i]] = i;
        }
        return false;
    }
};