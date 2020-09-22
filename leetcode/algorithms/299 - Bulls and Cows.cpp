class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        const int n = guess.size();
        vector<int> cnt(10, 0);
        int s, g;
        
        for (int i = 0; i < n; i++) {
            s = secret[i] - '0';
            g = guess[i] - '0';
            
            if (s == g) {
                bulls++;
            }
            else {
                if (cnt[s] < 0) {
                    cows++;
                }
                if (cnt[g] > 0) {
                    cows++;
                }
                cnt[s]++;
                cnt[g]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};