class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> res = arr;
        int prev, tmp;
        
        for (int i = 0; i < 100; i++) {
            prev = res[0];
            
            for (int i = 1; i < res.size() - 1; i++) {
                tmp = res[i];
                
                if (prev > res[i] && res[i] < res[i + 1]) {
                    res[i]++;
                }
                else if (prev < res[i] && res[i] > res[i + 1]) {
                    res[i]--;
                }
                
                prev = tmp;
            }
        }
        
        return res;
    }
};