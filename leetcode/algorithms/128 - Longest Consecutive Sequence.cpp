class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0, cur, streak;
        unordered_set<int> seen;
        
        for (auto& i: nums) {
            seen.insert(i);
        }
        
        for (auto& i: nums) {
            if (seen.count(i - 1) == 0) {
                cur = i;
                streak = 0;
                
                while (seen.count(cur) > 0) {
                    seen.erase(cur++);
                    streak++;
                }
                
                res = max(res, streak);
            }
        }
        
        return res;
    }
};