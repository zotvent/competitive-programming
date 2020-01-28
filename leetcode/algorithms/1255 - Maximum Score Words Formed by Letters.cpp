class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        
        for (auto c: letters) {
            freq[c - 'a']++;
        }
        
        return dfs(words, score, freq, 0);
    }
    
    int dfs(vector<string>& words, vector<int>& score, vector<int>& frequency, int index) {
        if (index >= words.size()) {
            return 0;
        }
        
        int next = dfs(words, score, frequency, index + 1);
        
        vector<int> cur_freq = frequency;
        int cur_score = 0;
        bool valid = true;
        
        for (auto c: words[index]) {
            if (--cur_freq[c - 'a'] < 0) {
                valid = false;
            }
            cur_score += score[c - 'a'];
        }
        
        if (valid) {
            cur_score += dfs(words, score, cur_freq, index + 1);
        }
        else {
            cur_score = 0;
        }
        
        return max(next, cur_score);
    }
};