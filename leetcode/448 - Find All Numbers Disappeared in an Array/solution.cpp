class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int j = abs(nums[i]) - 1;
            if (nums[j] > 0) {
            	nums[j] = -nums[j];
            }
        }
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                v.push_back(i+1);
            }
        }
        return v;
    }
};