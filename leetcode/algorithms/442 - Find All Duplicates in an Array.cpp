class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        int index;
        
        for (auto& i: nums) {
            index = abs(i) - 1;
            if (nums[index] < 0) {
                res.push_back(index + 1);
            }
            nums[index] *= -1;
        }
        
        return res;
    }
};