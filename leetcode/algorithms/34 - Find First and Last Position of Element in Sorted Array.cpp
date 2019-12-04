class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binary_search(nums, target, true, 0);
        int end = -1;
                
        if (start == nums.size()) start = -1;
        else end = binary_search(nums, target, false, start);
        
        return {start, end};
    }
    
    int binary_search(vector<int>& nums, int target, bool leftMost, int start) {
        int res = leftMost ? nums.size() : 0;
        
        int l = start;
        int r = nums.size() - 1;
        int m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            if (nums[m] == target) {
                if (leftMost) {
                    res = min(res, m);
                    r = m - 1;
                }
                else {
                    res = max(res, m);
                    l = m + 1;
                }
            }
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        
        return res;
    }
};