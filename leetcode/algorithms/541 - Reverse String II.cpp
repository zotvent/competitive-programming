class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            int start = i, end = min((int) s.length(), i+k);
            for (int j = 0; j < (end-start)/2; j++) 
                swap(s[start+j], s[end-j-1]);
        }
        return s;
    }
};