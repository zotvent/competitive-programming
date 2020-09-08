class Solution {
    
    void rec(int num, int N, int K, int length, vector<int>& res) {
        if (length == N) {
            res.push_back(num);
            return;
        }
        
        if (K == 0) {
            int last = num % 10;
            rec(num * 10 + last, N, K, length + 1, res);
        }
        else {
            int last = num % 10;
            
            if (last - K >= 0) {
                rec(num * 10 + last - K, N, K, length + 1, res);
            }
            
            if (last + K < 10) {
                rec(num * 10 + last + K, N, K, length + 1, res);
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;
        int start = (N == 1) ? 0 : 1;
        
        for (int i = start; i <= 9; i++) {
            rec(i, N, K, 1, res);
        }
        
        return res;
    }
};