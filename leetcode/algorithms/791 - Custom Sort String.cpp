class Solution {
    
    int charToInt(int c) {
        return c - 'a';
    }
    
public:
    string customSortString(string order, string str) {
        string res = "";
        vector<int> m(26, 0); // frequency
        
        for (auto& i: str) {
            m[charToInt(i)]++;
        }
        
        for (auto& i: order) {
            for (int j = 0; j < m[charToInt(i)]; j++) {
                res.push_back(i);
            }
            m[charToInt(i)] = 0;
        }
        
        for (auto& i: str) {
            for (int j = 0; j < m[charToInt(i)]; j++) {
                res.push_back(i);
            }
            m[charToInt(i)] = 0;
        }
        
        return res;
    }
};