class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if (B > A) {
            return strWithout3a3b(B, A, b, a);
        }
        
        while (A-- > 0) {
            res.push_back(a);
            
            if (A > B) {
                res.push_back(a);
                A--;
            }
            
            if (B-- > 0) {
                res.push_back(b);
            }
        }
        
        return res;
    }
};