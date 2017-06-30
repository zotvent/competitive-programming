class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = 40000, b = 40000;
        
        if (ops.size() == 0) {
            a = m;
            b = n;
        }
        else {
            for (int i = 0; i < ops.size(); i++) {
                a = min(a, ops[i][0]);
                b = min(b, ops[i][1]);
            }
        }
        
        return a * b;
    }
};