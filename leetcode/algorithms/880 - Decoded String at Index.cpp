class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 0;
        const int n = S.size();
        
        for (int i = 0; i < n; i++) {
            if (isalpha(S[i])) {
                size++;
            }
            else {
                size *= S[i] - '0';
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            K %= size;
            
            if (K == 0 && isalpha(S[i])) {
                return S.substr(i, 1);
            }
            
            if (isdigit(S[i])) {
                size /= S[i] - '0';
            }
            else {
                size--;
            }
        }
        
        return "";
    }
};