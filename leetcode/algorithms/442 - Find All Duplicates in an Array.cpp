class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int correct = abs(nums[i]) - 1;
            
            if (nums[correct] < 0)
                res.push_back(abs(nums[i]));
            else
                nums[correct] = -nums[correct];
        }
            
        return res;
    }
};