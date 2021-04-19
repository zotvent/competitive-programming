class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res, used(n + 1, 0);
        int step = k;
        
        res.push_back(1);
        used[1] = 1;
        
        for (int i = 1; i < n; i++) {
            if (step == 0) {
                for (int j = 2 + k; i < n; j++, i++) {
                    res.push_back(j);
                }
            }
            else if (res[i - 1] - step < 1 || used[res[i - 1] - step]) {
                res.push_back(res[i - 1] + step);
                used[res[i - 1] + step] = 1;
                step--;
            }
            else {
                res.push_back(res[i - 1] - step);
                used[res[i - 1] - step] = 1;
                step--;
            }
        }
        
        return res;
    }
};