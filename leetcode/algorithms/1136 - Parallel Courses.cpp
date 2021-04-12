class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, unordered_set<int>> g, rev;
        unordered_set<int> cur, used;
        int left = n, sum = 0, res = 0;
        
        for (auto& i: relations) {
            g[i[1]].insert(i[0]); // parent -> child
            rev[i[0]].insert(i[1]); // child -> parent
        }
        
        while (left > 0) {
            sum = 0;
            
            for (int i = 1; i <= n; i++) {
                if (g.count(i) == 0 && used.count(i) == 0) {
                    cur.insert(i);
                    used.insert(i);
                    sum++;
                }
            }
            
            for (auto i = cur.begin(); i != cur.end(); i++) {
                for (auto it = rev[*i].begin(); it != rev[*i].end(); it++) {
                    g[*it].erase(*i);
                    if (g[*it].empty()) {
                        g.erase(*it);
                    }
                }
                rev.erase(*i);
            }
            
            if (sum == 0) {
                return -1;
            }
            res++;
            left -= sum;
        }
        
        return res;
    }
};