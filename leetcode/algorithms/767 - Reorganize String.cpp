class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        
        vector<int> freq(26, 0);
        
        for (auto& c: S) {
            freq[c - 'a'] += 100;
        }
        for (int i = 0; i < freq.size(); i++) {
            freq[i] += i;
        }
        
        sort(freq.begin(), freq.end());
        
        int head = 0;
        int tail = freq.size() - 1;
        
        int n = S.size();
        res.resize(n);
        
        char c;
        int cnt;
        
        while (tail >= 0) {
            cnt = freq[tail] / 100;
            c = 'a' + (freq[tail] % 100);
            
            if (cnt > (n + 1) / 2) {
                res = "";
                break;
            }
            
            for (int i = 0; i < cnt; i++) {
                res[head] = c;
                head += 2;
                if (head >= n) {
                    head = 1;
                }
            }
            
            tail--;
        }
        
        return res;
    }
};