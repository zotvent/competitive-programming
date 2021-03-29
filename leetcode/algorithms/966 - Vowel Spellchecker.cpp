class Solution {
    
    string deVowel(string s) {
        s = toLower(s);
        for (auto& c: s) {
            if (c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o') {
                c = '*';
            }
        }
        return s;
    }
    
    string toLower(string s) {
        for (auto& c: s) {
            c = tolower(c);
        }
        return s;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string> queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowers, devowels;
        string tolow, todev;
        
        for (string w : wordlist) {
            tolow = toLower(w), todev = deVowel(w);
            lowers.insert({tolow, w});
            devowels.insert({todev, w});
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            if (words.count(queries[i])) continue;
            tolow = toLower(queries[i]), todev = deVowel(queries[i]);
            
            if (lowers.count(tolow)) {
                queries[i] = lowers[tolow];
            }
            else if (devowels.count(todev)) {
                queries[i] = devowels[todev];
            }
            else {
                queries[i] = "";
            }
        }
        
        return queries;
    }
};