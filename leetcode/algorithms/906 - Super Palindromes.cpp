class Solution {
    
    bool isPalindrome(long long x) {
        return x == reverse(x);
    }
    
    long long reverse(long long x) {
        long long res = 0;
        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
    
    void calc(int shift, long long l, long long r, int& res) {
        const int magic = 1e5;
        string cur = "";
        long long x;
        
        for (int i = 1; i < magic; i++) {
            cur = to_string(i);
            for (int j = cur.size() - 1 - shift; j >= 0; j--) {
                cur.push_back(cur[j]);
            }
            x = stol(cur);
            x *= x;
            if (x > r) break;
            if (x >= l && isPalindrome(x)) res++;
        }
    }
    
public:
    int superpalindromesInRange(string left, string right) {
        int res = 0;
        long long l = stol(left);
        long long r = stol(right);
        
        calc(1, l, r, res); // odd
        calc(0, l, r, res); // even
        
        return res;
    }
};