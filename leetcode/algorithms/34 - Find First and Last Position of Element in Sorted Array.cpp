class Solution {
    
    int findExtremeIndex(vector<int>& nums, int target, bool leftMost) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        
        while (l + 1 < r) {
            m = l + (r - l) / 2;
            
            if (nums[m] > target || (leftMost && nums[m] == target)) r = m;
            else l = m;
        }
        
        if (!leftMost) {
            swap(l, r);
        }
        
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        
        int l = findExtremeIndex(nums, target, true);
        int r = findExtremeIndex(nums, target, false);
        return {l, r};
    }
};