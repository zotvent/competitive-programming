class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<int> used(n, 0);
        queue<int> q;
        
        q.push(0);
        used[0] = 1;
        int cnt = 1, top, key;
        
        while (!q.empty()) {
            top = q.front();
            q.pop();
            
            for (int i = 0; i < rooms[top].size(); i++) {
                key = rooms[top][i];
                
                if (!used[key]) {
                    q.push(key);
                    used[key] = 1;
                    cnt++;
                }
            }
        }
        
        return cnt == rooms.size();
    }
};