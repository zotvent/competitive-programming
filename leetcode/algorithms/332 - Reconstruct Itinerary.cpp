class Solution {
    bool dfs(string v, map<string, map<string, int>>& g, vector<string>& path, int flights) {
        path.push_back(v);
        
        if (flights == 0) {
            return true;
        }
        
        for (auto& to: g[v]) {
            if (to.second > 0) {
                to.second--;
                bool res = dfs(to.first, g, path, flights - 1);
                to.second++;
                
                if (res) return true;
            }
        }
        
        path.pop_back();
        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        map<string, map<string, int>> g;
        int flights = 0;
        
        for (auto& i: tickets) {
            g[i[0]][i[1]]++;
            flights++;
        }
        
        dfs("JFK", g, res, flights);
        return res;
    }
};