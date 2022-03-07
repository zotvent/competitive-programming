class WordDistance {
    int size;
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& wordsDict) {
        size = wordsDict.size();
        for (int i = 0; i < size; i++) {
            m[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = size - 1;
        const int n1 = m[word1].size();
        const int n2 = m[word2].size();
        int i1 = 0, i2 = 0;
        
        while (i1 < n1 && i2 < n2) {
            res = min(res, abs(m[word1][i1] - m[word2][i2]));
            if (m[word1][i1] < m[word2][i2]) {
                i1++;
            }
            else i2++;
        }
        
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */