class Solution {
    
    bool check(int index, vector<int>& used) {
        return index >= 0 && index < used.size() && !used[index];
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        vector<int> used(n, 0);
        queue<int> q;
        int v;
        
        q.push(start);
        used[start] = 1;
        
        while (!q.empty()) {
            v = q.front();
            q.pop();
            
            if (arr[v] == 0) {
                return true;
            }
            
            if (check(v - arr[v], used)) {
                q.push(v - arr[v]);
                used[v - arr[v]] = 1;
            }
            
            if (check(v + arr[v], used)) {
                q.push(v + arr[v]);
                used[v + arr[v]] = 1;
            }
        }
        
        return false;
    }
};