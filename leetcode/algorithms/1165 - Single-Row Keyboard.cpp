class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0, prev = 0;
        unordered_map<char, int> m;
        
        for (int i = 0; i < keyboard.size(); i++) {
            m[keyboard[i]] = i;
        }
        
        for (auto& i: word) {
            res += abs(prev - m[i]);
            prev = m[i];
        }
        
        return res;
    }
};