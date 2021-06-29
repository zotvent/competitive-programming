/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    
    int match(string& a, string& b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                res++;
            }
        }
        return res;
    }
    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> next;
        vector<vector<int>> cnt;
        string candidate;
        int best, score;
        
        for (int test = 0, guessed = 0; test < 10 && guessed < 6; test++) {
            cnt.assign(6, vector<int>(26, 0));
            for (auto& w: wordlist) {
                for (int i = 0; i < w.size(); i++) {
                    cnt[i][w[i] - 'a']++;
                }
            }
            
            best = 0;
            for (auto& w: wordlist) {
                score = 0;
                for (int i = 0; i < w.size(); i++) {
                    score += cnt[i][w[i] - 'a'];
                }
                
                if (score > best) {
                    best = score;
                    candidate = w;
                }
            }
            
            guessed = master.guess(candidate);
            
            for (auto& w: wordlist) {
                if (candidate != w && match(candidate, w) == guessed) {
                    next.push_back(w);
                }
            }
            
            wordlist = next;
            next.clear();
        }
    }
};