class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        int start, end, inc;
        
        for (auto& i: updates) {
            start = i[0], end = i[1], inc = i[2];
            res[start] += inc;
            if (end + 1 < length) {
                res[end + 1] -= inc;
            }
        }
        
        for (int i = 1; i < length; i++) {
            res[i] += res[i - 1];
        }
        
        return res;
    }
};