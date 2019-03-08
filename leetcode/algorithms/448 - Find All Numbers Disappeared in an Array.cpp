class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i]) - 1;
            
            if (nums[j] > 0) {
                nums[j] = -nums[j];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        
        return res;
    }
};