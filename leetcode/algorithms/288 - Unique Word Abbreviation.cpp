class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> m;
    
    string key(string word) {
        if (word.size() < 3) {
            return word;
        }
        else {
            string res = word.substr(0, 1);
            res += to_string(word.size() - 2);
            res.push_back(word.back());
            
            return res;
        }
    }
    
public:
    ValidWordAbbr(vector<string>& dictionary) {
        string abbreviation;
        
        for (auto& word: dictionary) {
            if (word.size() < 3) {
                m[word].insert(word);
            }
            else {
                abbreviation = key(word);
                m[abbreviation].insert(word);
            }
        }
    }
    
    bool isUnique(string word) {
        string abbreviation = key(word);
        
        return m.count(abbreviation) == 0 || (m[abbreviation].size() == 1 && m[abbreviation].count(word) > 0);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */