class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        
        while (Y > X) {
            res++;
            
            if (Y % 2 == 1) Y++;
            else Y /= 2;
        }
        
        return res + X - Y;
    }
};