class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        
        map<int, int> cnt;
        for (auto i: nums) cnt[i]++;
        
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            while (it->second) {
                for (int i = 0; i < k; i++) {
                    if (!cnt[it->first + i]) {
                        return false;
                    }
                    else {
                        cnt[it->first + i]--;
                    }
                }
            }
        }
        
        return true;
    }
};