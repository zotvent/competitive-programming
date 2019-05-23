class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;

        sort(nums.begin(), nums.end());

        int l, m, r, sum;

        for (int i = 1; i < nums.size() - 1; i++) {
            m = nums[i];

            l = 0;
            r = nums.size() - 1;

            while (l < i && i < r) {
                sum = nums[l] + m + nums[r];
                if (res == INT_MAX || abs(res - target) > abs(sum - target)) {
                    res = sum;
                }

                if (sum == target) break;
                else if (sum < target) l++;
                else r--;
            }
        }

        return res;
    }
};