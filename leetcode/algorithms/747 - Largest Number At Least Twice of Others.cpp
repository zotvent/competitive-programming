class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> mx(2, -1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (mx[1] == -1 || nums[i] > nums[mx[1]]) {
                mx[0] = mx[1];
                mx[1] = i;
            }
            else if (mx[0] == -1 || nums[i] > nums[mx[0]]) {
                mx[0] = i;
            }
        }
        
        int res = -1;
        
        if (nums.size() == 1) {
            res = 0;
        }
        else if (mx[0] != -1 && mx[1] != -1 && nums[mx[0]] * 2 <= nums[mx[1]]) {
            res = mx[1];
        }
        
        return res;
    }
};