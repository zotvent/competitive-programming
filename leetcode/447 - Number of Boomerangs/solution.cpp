class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> m(points.size());
            
            for (int j = 0; j < points.size(); j++) {
                if (i == j) 
                    continue;
                
                int dx = points[i].first-points[j].first;
                int dy = points[i].second-points[j].second;
                int key = dx*dx + dy*dy;
                
                m[key]++;
            }
            
            for (auto item : m) {
                if (item.second > 0)
                    res += item.second * (item.second-1);
            }
        }
        
        return res;
    }
};