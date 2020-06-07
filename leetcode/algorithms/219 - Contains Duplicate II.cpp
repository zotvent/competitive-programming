class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i]) > 0) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};