class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int l = 0;
        int r = max(
            abs(heaters[0] - houses[0]),
            abs(heaters[0] - houses[houses.size() - 1])
        );
        
        while (l <= r) {
            int m = (r - l) / 2 + l;
            int cnt = 0;
            
            for (int i = 0; i < houses.size(); i++) {
                if (binary_search(houses[i], heaters, m)) {
                    cnt++;
                }
            }
            
            if (cnt < houses.size()) {
                l = m + 1;
            }
            else {
                res = m;
                r = m - 1;
            }
        }
        
        return res;
    }
    
    bool binary_search(int x, vector<int>& v, int radius) {
        int l = 0;
        int r = v.size() - 1;
        
        while (l <= r) {
            int m = (r - l) / 2 + l;
            int vi = v[m];
            
            if (vi - radius <= x && x <= vi + radius) {
                return true;
            }
            else if (x < vi - radius) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        return false;
    }
};