class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(rooms, visited, 0);
        
        for (auto i: visited)
            if (!i) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int v) {
        visited[v] = 1;
        for (int i = 0; i < rooms[v].size(); i++) {
            int key = rooms[v][i];
            if (!visited[key])
                dfs(rooms, visited, key);
        }
    }
};