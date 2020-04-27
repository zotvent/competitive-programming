class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = (int) nums.size() - 1;
        
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= pos) {
                pos = i;
            }
        }
        
        return pos == 0;
    }
};