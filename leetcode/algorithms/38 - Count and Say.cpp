class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        int cnt;
        char c;
        string cur;
        
        for (int i = 1; i < n; i++) {
            cnt = 1;
            c = res[0];
            
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == c) cnt++;
                else {
                    cur.push_back(cnt + '0');
                    cur.push_back(c);
                    
                    c = res[j];
                    cnt = 1;
                }
            }
            
            cur.push_back(cnt + '0');
            cur.push_back(c);
            
            res = cur;
            cur.clear();
        }
        
        return res;
    }
    
    void calc(int n, unordered_map<int, string>& m) {
        
    }
};