class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        
        int mx = 0;
        for (auto i: candies) {
            mx = max(mx, i);
        }
        
        for (auto i: candies) {
            res.push_back(i + extraCandies >= mx);
        }
        
        return res;
    }
};