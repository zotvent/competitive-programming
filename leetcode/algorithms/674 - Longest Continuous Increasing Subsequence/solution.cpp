class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++)
            if (i == 0 || nums[i] > nums[i-1])
                res = max(res, ++cur);
            else
                cur = 1;
        return res;
    }
};