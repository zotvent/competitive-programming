class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        map<string, int> dict;

        countWords(A, dict);
        countWords(B, dict);
        for (auto it = dict.begin(); it != dict.end(); it++)
            if (it->second == 1)
                res.push_back(it->first);
        
        return res;
    }

    void countWords(string s, map<string, int>& m) {
        while (s.find(' ') != string::npos) {
            int space = s.find(' ');
            m[s.substr(0, space)]++;
            s = s.substr(space + 1);
        }
        m[s]++;
    }
};