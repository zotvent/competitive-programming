class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        const int height = wall.size();
        int res = height, sum, edges = 0;
        unordered_map<int, int> m;
        
        for (auto& row: wall) {
            sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                m[sum]++;
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            res = min(res, height - it->second);
        }
        
        return res;
    }
};