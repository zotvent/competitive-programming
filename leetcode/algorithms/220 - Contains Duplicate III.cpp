class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long long> window;
        set<long long>::iterator lower;
        long long tl = t;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }
            lower = window.lower_bound((long long) nums[i] - tl);

            if (lower != window.end() && *lower - nums[i] <= tl) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};