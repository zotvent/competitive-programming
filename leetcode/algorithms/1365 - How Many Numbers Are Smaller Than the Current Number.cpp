class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> cnt(101);
        
        for (auto i: nums) {
            cnt[i]++;
        }
        
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        for (auto i: nums) {
            res.push_back((i == 0 ? 0 : cnt[i - 1]));
        }
        
        return res;
    }
};