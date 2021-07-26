class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int head = 0;

        for (auto& i: nums) {
            if (i != val) {
                swap(nums[head++], i);
            }
        }
        
        return head;
    }
};