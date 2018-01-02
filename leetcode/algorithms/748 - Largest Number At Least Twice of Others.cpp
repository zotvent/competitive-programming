class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = nums[0], index = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > mx) {
                mx = nums[i];
                index = i;
            }
        bool ok = true;
        for (int i = 0; i < nums.size(); i++)
            if (i != index && mx < 2*nums[i])
                ok = false;
        return (ok ? index : -1);
    }
};