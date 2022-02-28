class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        const int n = arr.size();
        int res = n;
        int l = 0, r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == m) {
                res = min(res, m);
            }
            
            if (arr[m] >= m) r = m - 1;
            else l = m + 1;
        }
        
        return (res == n ? -1 : res);
    }
};