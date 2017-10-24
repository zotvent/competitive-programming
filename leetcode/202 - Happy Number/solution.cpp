class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(s.count(n) == 0) {
            s.insert(n);
            n = calc(n);
        }
        return n == 1;
    }
    
    int calc(int n) {
        int res = 0;
        while(n > 0) {
            int temp = n%10;
            res += temp * temp;
            n /= 10;
        }
        return res;
    }
};