class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        int left, add;
        
        for (int i = 0; i < n; i++) {
            left = n - i - 1;
            
            if (k > left * 26) {
                add = k - left * 26;
                res.push_back('a' + add - 1);
                k -= add;
            }
            else {
                res.push_back('a');
                k--;
            }
        }
        
        return res;
    }
};