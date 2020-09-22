class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {      
        if (numerator == 0) {
            return "0";
        }
        
        long long num = abs(numerator);
        long long den = abs(denominator);
        
        long long integerPart = num / den;
        num -= den * integerPart;
        
        string res = "";
        if (numerator < 0 ^ denominator < 0) {
            res.push_back('-');
        }
        res += to_string(integerPart);
        
        vector<pair<long long, long long>> fractionPart;
        unordered_set<long long> seen;
        long long next;
        
        while (seen.count(num) == 0 && num != 0) {
            seen.insert(num);
            next = num * 10 / den;
            fractionPart.push_back({num, next});
            num = num * 10 - next * den;
        }
        
        if (!fractionPart.empty()) {
            res.push_back('.');
            
            int i;
            for (i = 0; i < fractionPart.size(); i++) {
                if (fractionPart[i].first == num) {
                    break;
                }
                res.push_back(fractionPart[i].second + '0');
            }
            
            if (i < fractionPart.size()) {
                res.push_back('(');
                
                while (i < fractionPart.size()) {
                    res.push_back(fractionPart[i++].second + '0');
                }
                
                res.push_back(')');
            }
        }
        
        return res;
    }
};