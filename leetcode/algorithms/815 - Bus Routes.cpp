class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); i++) {
            for (auto& stop: routes[i]) {
                to_routes[stop].push_back(i);
            }
        }
        queue<pair<int, int>> bfs;
        bfs.push({source, 0});
        unordered_set<int> seen = {source};
        while (!bfs.empty()) {
            int stop = bfs.front().first;
            int buses = bfs.front().second;
            bfs.pop();
            if (stop == target) return buses;
            for (auto& i: to_routes[stop]) {
                for (auto& j: routes[i]) {
                    if (seen.count(j) == 0) {
                        seen.insert(j);
                        bfs.push({j, buses + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};
