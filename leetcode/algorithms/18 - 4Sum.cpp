class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        set<vector<int>> s;
        vector<int> v;
        int l, r, sum;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                l = 0;
                r = nums.size() - 1;
                
                while (l < r) {
                    if (l == i || l == j) {
                        l++;
                        continue;
                    }
                    if (r == i || r == j) {
                        r--;
                        continue;
                    }
                    
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        v = {nums[i], nums[j], nums[l], nums[r]};
                        sort(v.begin(), v.end());
                        s.insert(v);
                        v.clear();
                        l++;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }
        
        for (auto it = s.begin(); it != s.end(); ++it) res.push_back(*it);
        
        return res;
    }
};