class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int res = 0;
        
        vector<int> a = {1, 1};
        
        int inf = (int) 1e9;
        int cur = 1;
        
        while (cur < inf) {
            cur = a[(int) a.size() - 1] + a[(int) a.size() - 2];
            a.push_back(cur);
        }
        
        cur = (int) a.size() - 1;
        while (k > 0 && cur >= 0) {
            while (cur >= 0 && a[cur] > k) {
                cur--;
            }
            
            res += (k / a[cur]);
            k -= (k / a[cur]) * a[cur];
        }
        
        return res;
    }
};