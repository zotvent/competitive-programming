class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        int i = (int) a.size() - 1;
        int j = (int) b.size() - 1;
        int carry = 0;
        
        while (carry > 0 || i >= 0 || j >= 0) {            
            if (i >= 0) carry += (a[i--] - '0');
            if (j >= 0) carry += (b[j--] - '0');
            
            res.push_back((carry % 2) + '0');
            carry >>= 1;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};