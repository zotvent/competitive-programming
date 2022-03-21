// https://leetcode.com/problems/min-cost-to-connect-all-points/
class Solution {
    
    struct UnionFind {
        UnionFind(int n) {
            parents.resize(n);
            rank.assign(n, 0);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
        }
        
        bool connect(int l, int r) {
            int left = parent(l);
            int right = parent(r);
            
            if (left == right) {
                return false;
            }
            
            if (rank[left] == rank[right]) {
                parents[right] = left;
                rank[left]++;
            }
            else if (rank[left] > rank[right]) {
                parents[right] = left;
            }
            else {
                parents[left] = right;
            }
            
            return true;
        }
        
    private:
        vector<int> parents, rank;
        
        int parent(int id) {
            if (id == parents[id]) {
                return id;
            }
            return parents[id] = parent(parents[id]);
        }
    };
    
    int distance(vector<int>& l, vector<int>& r) {
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        const int n = points.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.push_back({distance(points[i], points[j]), i, j});
            }
        }
        
        sort(edges.begin(), edges.end());
        UnionFind uf(n);
        int used = 0, head = 0, res = 0;
        
        while (used != n - 1) {
            if (uf.connect(edges[head][1], edges[head][2])) {
                used++;
                res += edges[head][0];
            }
            head++;
        }
        
        return res;
    }
};