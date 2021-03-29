class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int> m;
        const int rows = mat.size();
        const int cols = mat[0].size();
        
        for (auto& i: mat[0]) {
            m[i]++;
        }
        
        for (int i = 1; i < rows; i++) {
            for (auto& j: mat[i]) {
                if (m.count(j) > 0) {
                    m[j]++;
                }
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == rows) {
                return it->first;
            }
        }
        
        return -1;
    }
};