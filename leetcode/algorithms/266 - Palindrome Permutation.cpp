class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int odd = 0;
        
        for (auto& i: s) {
            m[i]++;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second % 2 == 1) {
                odd++;
            }
        }
        
        return odd < 2;
    }
};