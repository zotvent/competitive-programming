class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        
        if (nums.empty()) return res;
        
        bool biggerOrEqualsFirstElement = target >= nums[0];
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int m = (r - l) / 2 + l;
            
            if (nums[m] == target) {
                res = m;
                break;
            }
            
            if (biggerOrEqualsFirstElement) {
                if (nums[m] > target) r = m - 1;
                else {
                    if (nums[m] >= nums[0]) l = m + 1;
                    else r = m - 1;
                }
            }
            else {
                if (nums[m] > target) {
                    if (nums[m] >= nums[0]) l = m + 1;
                    else r = m - 1;
                }
                else l = m + 1;
            }
        }
        
        return res;
    }
};