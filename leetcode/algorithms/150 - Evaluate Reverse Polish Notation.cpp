class Solution {
    
    bool isSign(string& s) {
        return s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/');
    }
    
    int calc(int left, int right, string sign) {
        if (sign == "+") return left += right;
        else if (sign == "-") left -= right;
        else if (sign == "*") left *= right;
        else left /= right;
        return left;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        int last;
        
        for (auto& t: tokens) {
            if (isSign(t)) {
                last = nums.back();
                nums.pop_back();
                nums.back() = calc(nums.back(), last, t);
            }
            else nums.push_back(stoi(t));
        }
        
        return nums.back();
    }
};