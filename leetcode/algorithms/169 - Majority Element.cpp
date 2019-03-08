class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int cnt = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt++;
                res = nums[i];
            }
            else if (res == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        
        return res;
    }
};