class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string, int> dict;
        for (int i = 0; i < deadends.size(); i++)
            dict[deadends[i]] = 1;
        
        map<string, int> used, d;
        queue<string> q;
        string start = "0000";
        
        used[start] = 1;
        d[start] = 0;
        q.push(start);
        
        if (!dict[start]) {
            while (!q.empty()) {
                string v = q.front();
                q.pop();
                for (int index = 0; index < 4; index++) {
                    for (int dir = -1; dir <= 1; dir += 2) {
                        string to = rotate(v, index, dir);
                        if (!used[to] && !dict[to]) {
                            used[to] = 1;
                            q.push(to);
                            d[to] = d[v] + 1;
                        }  
                    }
                }
            }
        }
        
        return (used[target] == 1 ? d[target] : -1);
    }
    
    string rotate(string s, int index, int dir) {
        if (s[index] == '0' && dir == -1)
            s[index] = '9';
        else if (s[index] == '9' && dir == 1)
            s[index] = '0';
        else
            s[index] += dir;
        return s;
    }
};