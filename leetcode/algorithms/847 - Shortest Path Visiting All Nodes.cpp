class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1) {
            return 0;
        }
        
        const int n = graph.size();
        const int finalMask = (1 << n) - 1;
        vector<vector<int>> seen(n, vector<int>(finalMask));
        vector<vector<int>> state;
        int steps = 0;
        
        for (int i = 0; i < n; i++) {
            state.push_back({i, 1 << i});
            seen[i][1 << i] = true;
        }
        
        while (!state.empty()) {
            vector<vector<int>> nextState;
            
            for (auto& i: state) {
                int node = i[0];
                int mask = i[1];
                
                for (auto& neighbor: graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    
                    if (nextMask == finalMask) {
                        return steps + 1;
                    }
                    
                    if (!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        nextState.push_back({neighbor, nextMask});
                    }
                }
            }
            
            steps++;
            state = nextState;
        }
        
        return -1;
    }
};