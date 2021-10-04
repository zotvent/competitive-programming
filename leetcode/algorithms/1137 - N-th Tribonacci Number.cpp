class Solution {
public:
    int tribonacci(int n) {
        vector<int> last(3, 1);
        last[0] = 0;
        
        if (n < last.size()) {
            return last[n];
        }
        
        for (int i = 3; i <= n; i++) {
            int next = last[0] + last[1] + last[2];
            last[0] = last[1];
            last[1] = last[2];
            last[2] = next;
        }
        
        return last[2];
    }
};