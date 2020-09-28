class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        
        const int n = nums.size();
        vector<int> candidates(2, 0);
        vector<int> cnt(2, 0);
        
        for (auto& i: nums) {
            if (cnt[0] > 0 && i == candidates[0]) {
                cnt[0]++;
            }
            else if (cnt[1] > 0 && i == candidates[1]) {
                cnt[1]++;
            }
            else if (cnt[0] == 0) {
                candidates[0] = i;
                cnt[0] = 1;
            }
            else if (cnt[1] == 0) {
                candidates[1] = i;
                cnt[1] = 1;
            }
            else {
                cnt[0]--;
                cnt[1]--;
            }
        }
        
        // printf("%d, %d\n", candidates[0], candidates[1]);
        
        cnt.assign(2, 0);
        
        for (auto& i: nums) {
            if (i == candidates[0]) cnt[0]++;
            else if (i == candidates[1]) cnt[1]++;
        }
        
        if (cnt[0] > n / 3) res.push_back(candidates[0]);
        if (cnt[1] > n / 3) res.push_back(candidates[1]);
        
        return res;
    }
};