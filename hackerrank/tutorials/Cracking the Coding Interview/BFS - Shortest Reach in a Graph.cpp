#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    vector<vector<int>> g;
    
public:
    Graph(int n) {
        g.assign(n, vector<int>());
    }
    
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> shortest_reach(int start) {
        int const inf = (int) 1e9;
        vector<int> used(g.size(), 0);
        vector<int> d(g.size(), inf);
        queue<int> q;
        
        q.push(start);
        used[start] = 1;
        d[start] = 0;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v][i];
                if (!used[to] && d[to] > d[v] + 6) {
                    used[to] = 1;
                    d[to] = d[v] + 6;
                    q.push(to);
                }
            }
        }
        for (int i = 0; i < d.size(); i++)
            if (d[i] == inf)
                d[i] = -1;
        
        return d;
    }
    
};

int main() {
    int queries;
    cin >> queries;
    
    for (int t = 0; t < queries; t++) {
        
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);
        
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
