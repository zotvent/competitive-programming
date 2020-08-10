class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.back() - nums[0];
        int m, cnt;
        int n = nums.size();
        
        while (l < r) {
            cnt = 0;
            m = l + (r - l) / 2;
            
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j] <= nums[i] + m) {
                    j++;
                }
                cnt += j - i - 1;
            }
            
            if (cnt >= k) r = m;
            else l = m + 1;
        }
        
        return l;
    }
};