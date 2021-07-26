class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        int res = 0, k;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            k = i + 2;
            for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
                while (k < n && nums[k] < nums[i] + nums[j]) {
                    k++;
                }
                res += k - j - 1;
            }
        }
        
        return res;
    }
};