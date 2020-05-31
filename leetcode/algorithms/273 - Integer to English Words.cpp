class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        
        int billion = num / (int) 1e9;
        int million = (num - billion * (int) 1e9) / (int) 1e6;
        int thousand = (num - billion * (int) 1e9 - million * (int) 1e6) / (int) 1e3;
        int rest = num - billion * (int) 1e9 - million * (int) 1e6 - thousand * (int) 1e3;
        
        string res = "";
        
        if (billion > 0) {
            res = three(billion) + " Billion";
        }
        if (million > 0) {
            if (!res.empty()) {
                res.push_back(' ');
            }
            res += three(million) + " Million";
        }
        if (thousand > 0) {
            if (!res.empty()) {
                res.push_back(' ');
            }
            res += three(thousand) + " Thousand";
        }
        if (rest > 0) {
            if (!res.empty()) {
                res.push_back(' ');
            }
            res += three(rest);
        }
        
        return res;
    }
    
    string three(int num) {
        int hundred = num / 100;
        int rest = num - hundred * 100;
        
        string res = "";
        
        if (hundred > 0 && rest > 0) {
            res = one(hundred) + " Hundred " + two(rest);
        }
        else if (rest > 0) {
            res = two(rest);
        }
        else if (hundred > 0) {
            res = one(hundred) + " Hundred";
        }
        
        return res;
    }
    
    string two(int num) {
        if (num == 0) {
            return "";
        }
        else if (num < 10) {
            return one(num);
        }
        else if (num < 20) {
            return twoLessThan20(num);
        }
        else {
            int tenner = num / 10;
            int rest = num - tenner * 10;
            
            if (rest > 0) {
                return ten(tenner) + " " + one(rest);
            }
            else {
                return ten(tenner);
            }
        }
    }
    
    string one(int num) {
        switch (num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            default: return "";
        }
    }
    
    string twoLessThan20(int num) {
        switch (num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            default: return "";
        }
    }
    
    string ten(int num) {
        switch (num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
            default: return "";
        }
    }
};