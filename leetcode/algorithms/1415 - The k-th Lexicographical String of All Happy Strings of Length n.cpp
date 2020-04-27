class Solution {
public:
    string getHappyString(int n, int k) {
        if (3 * (1 << (n - 1)) < k) return "";
        
        vector<string> v;
        
        calc("a", n, v);
        calc("b", n, v);
        calc("c", n, v);
        
        return v[k - 1];
    }
    
    void calc(string s, int& n, vector<string>& v) {
        if (s.size() == n) {
            v.push_back(s);
            return;
        }
        
        int last = s[(int) s.size() - 1] - 'a';
        int next1 = (last + 1) % 3;
        int next2 = (last + 2) % 3;
        
        calc(s + string(1, min(next1, next2) + 'a'), n, v);
        calc(s + string(1, max(next1, next2) + 'a'), n, v);
    }
};