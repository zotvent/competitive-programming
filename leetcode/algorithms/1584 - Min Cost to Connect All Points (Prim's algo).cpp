class Solution {
    
    int distance(vector<int>& l, vector<int>& r) {
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0, used = 0;
        const int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<int> visited(n, 0);
        visited[0] = 1;
        
        for (int i = 1; i < n; i++) {
            q.push({distance(points[0], points[i]), i}); // {distance, to}
        }
        
        while (!q.empty() && used != n - 1) {
            auto cur = q.top();
            q.pop();
            
            if (!visited[cur[1]]) {
                res += cur[0];
                visited[cur[1]] = 1;
                used++;
                
                for (int to = 0; to < n; to++) {
                    if (!visited[to]) {
                        q.push({distance(points[cur[1]], points[to]), to});
                    }
                }
            }
        }
        
        return res;
    }
};