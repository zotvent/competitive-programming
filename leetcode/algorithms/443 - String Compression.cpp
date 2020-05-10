class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        
        int head = 0;
        int prev = 0;
        string tmp;
        
        for (int i = 0; i < chars.size(); i++) {
            if (chars[prev] != chars[i]) {
                chars[head++] = chars[prev];
                
                if (i - prev > 1) {
                    tmp = to_string(i - prev);
                    for (auto c: tmp) {
                        chars[head++] = c;
                        res++;
                    }
                }
                
                res++;
                prev = i;
            }
        }
        
        chars[head++] = chars[prev];
        res++;
        
        if ((int) chars.size() - prev > 1) {
            tmp = to_string((int) chars.size() - prev);
            for (auto c: tmp) {
                chars[head++] = c;
                res++;
            }
        }
        
        return res;
    }
};