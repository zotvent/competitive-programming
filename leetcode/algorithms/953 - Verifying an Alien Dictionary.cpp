class Solution {
    
    bool less(string& left, string& right, unordered_map<char, int>& m) {
        int l = 0, r = 0;
        
        while (l < left.size() && r < right.size()) {
            if (m[left[l]] > m[right[r]]) {
                return false;
            }
            else if (m[left[l]] == m[right[r]]) {
                l++;
                r++;
            }
            else {
                return true;
            }
        }
        
        return l == left.size();
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); i++) {
            if (!less(words[i - 1], words[i], m)) {
                return false;
            }
        }
        
        return true;
    }
};