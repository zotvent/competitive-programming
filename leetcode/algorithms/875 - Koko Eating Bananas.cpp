class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = INT_MIN;
        
        for (auto& i: piles) {
            mx = max(mx, i);
        }
        
        int l = 1, r = mx;
        int res = mx;
        
        while (l <= r) {
            int k = l + (r - l) / 2;
            int hours = 0;
            
            for (auto& i: piles) {
                hours += (i + k - 1) / k;
            }
            
            if (hours <= h) {
                r = k - 1;
                res = min(res, k);
            }
            else l = k + 1;
        }
        
        return res;
    }
};