class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) 
            return nums.size();
        
        int index = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i-1])
                nums[index++] = nums[i];
        return index;
    }
};