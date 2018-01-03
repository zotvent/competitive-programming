class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
            else if (nums[i] < target) index = i;
        }
        return index+1;
    }
};