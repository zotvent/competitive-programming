class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            res[i] = i * 2 - n + 1;
        }
        
        return res;
    }
};