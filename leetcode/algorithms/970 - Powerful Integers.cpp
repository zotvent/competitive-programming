class Solution {
    
    void calc(int x, int y, int bound, unordered_set<int>& s) {
        int l = 1, r = 1;
        
        for (int i = 0; i < 21; i++) {
            if (l > bound) break;
            r = 1;
            for (int j = 0; j < 21; j++) {
                if (l + r > bound) break;
                s.insert(l + r);
                r *= y;
            }
            l *= x;
        }
    }
    
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
       
        calc(x, y, bound, s);
        calc(y, x, bound, s);
        
        return vector<int>(s.begin(), s.end());
    }
};