class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1, tail = n - 1;
        
        while (l <= r) {
            if (nums[l] * nums[l] > nums[r] * nums[r]) {
                res[tail--] = nums[l] * nums[l++];
            }
            else {
                res[tail--] = nums[r] * nums[r--];
            }
        }
        
        return res;
    }
};