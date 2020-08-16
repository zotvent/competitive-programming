class CombinationIterator {
    
    string characters;
    int combinationLength;
    
    vector<int> mask;
    bool hasNextStr;
    
    void moveNext(vector<int>& mask) {
        int i;
        int ones = 0;
        
        for (i = mask.size() - 1; i >= 0; i--) {
            if (i == mask.size() - 1) {
                ones += mask[i];
                continue;
            }
            
            if (mask[i] == 0) {
                continue;
            }
            
            if (mask[i + 1] == 0) {
                mask[i] = 0;
                mask[i + 1] = 1;
                break;
            }
            else {
                ones++;
            }
        }
        
        if (ones == combinationLength) {
            hasNextStr = false;
        }
        else if (ones > 0) {
            for (int j = i + 2; j < mask.size(); j++) {
                mask[j] = (ones > 0) ? 1 : 0;
                ones--;
            }
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters = characters;
        this->combinationLength = combinationLength;
        
        mask.assign(characters.size(), 0);
        hasNextStr = true;
        
        for (int i = 0; i < combinationLength; i++) {
            mask[i] = 1;
        }
    }
    
    string next() {
        string res = "";
        
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i]) {
                res.push_back(characters[i]);
            }
        }
        
        moveNext(mask);
        
        return res;
    }
    
    bool hasNext() {
        return hasNextStr;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */