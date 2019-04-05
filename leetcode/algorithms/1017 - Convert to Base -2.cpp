class Solution {
public:
    string baseNeg2(int N) {
        string res = "";
        
        while (N != 0) {
            res = to_string(N & 1) + res;
            N = -(N >> 1);
        }
        
        return res.empty() ? "0" : res;
    }
};