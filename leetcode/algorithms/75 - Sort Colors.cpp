class Solution {
public:
    void sortColors(vector<int>& nums) {
        int head = 0;
        int tail = nums.size() - 1;
        
        for (int i = 0; i <= tail;) {
            if (nums[i] == 0) {
                swap(nums[head++], nums[i++]);
            }
            else if (nums[i] == 2) {
                swap(nums[tail--], nums[i]);
            }
            else {
                i++;
            }
        }
    }
};