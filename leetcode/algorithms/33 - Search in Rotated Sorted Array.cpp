class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;

        int l = 0;
        int r = (int) nums.size() - 1;
        int m;

        while (l <= r) {
            m = (r - l) / 2 + l;

            if (nums[m] == target) {
                res = m;
                break;
            }
            else if (nums[m] >= nums[l]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            }
            else {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }

        return res;
    }
};