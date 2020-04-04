class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        int l, r, sum;
        int target = 0;
        
        for (int i = 0; i < (int) nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                target = -nums[i];
                l = i + 1;
                r = nums.size() - 1;
                
                while (l < r) {
                    sum = nums[l] + nums[r];
                    
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        res.push_back({nums[i], nums[l], nums[r]});
                        
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        
                        l++;
                        r--;
                    }
                }
            }
        }
        
        return res;
    }
};