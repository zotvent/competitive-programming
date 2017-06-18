class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = 0, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) temp++;
            else temp = 0;
            n = max(n, temp);
        }
        return n;
    }
};