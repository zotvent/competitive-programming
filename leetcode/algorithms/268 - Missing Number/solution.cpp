class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, max = nums.size();
        for (int i = 0; i < nums.size(); i++) 
            res -= nums[i];
        return max*(max+1)/2 + res;
    }
};