class Solution {
public:
    int numWays(int n, int k) {
        vector<int> last = {k, k * k};
        
        for (int i = 3; i <= n; i++) {
            int next = (last[0] + last[1]) * (k - 1);
            last[0] = last[1];
            last[1] = next;
        }
        
        return last[min(n - 1, 1)];
    }
};