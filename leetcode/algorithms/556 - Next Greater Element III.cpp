class Solution {
    
    // to - inclusive
    int makeGreater(string& s, int from, int to) {
        int index;
        
        for (int left = to - 1; left >= 0; left--) {
            index = -1;
            
            for (int right = left + 1; right <= to; right++) {
                if (s[left] < s[right]) {
                    if (index == -1 || s[index] > s[right]) {
                        index = right;
                    }
                }
            }
            
            if (index != -1) {
                swap(s[left], s[index]);
                return left;
            }
        }
        
        return -1;
    }
    
    // to - inclusive
    void makeSmaller(string& s, int from, int to) {
        for (int left = from; left <= to; left++) {
            for (int right = left + 1; right <= to; right++) {
                if (s[left] > s[right]) {
                    swap(s[left], s[right]);
                }
            }
        }
    }
    
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        const int m = s.size();        
        
        int left = makeGreater(s, 0, m - 1);
        if (left != -1) {
            makeSmaller(s, left + 1, m - 1);
        }
        long long res = stol(s);
        
        return (left == -1 || res > INT_MAX ? -1 : res);
    }
};