class Solution {
    
    bool isSign(string& s) {
        return s.size() == 1 && (s == "-" || s == "+" || s == "*" || s == "/");
    }
    
    int calc(int left, int right, char sign) {
        switch (sign) {
            case '+': left += right; break;
            case '-': left -= right; break;
            case '*': left *= right; break;
            default: left /= right; break;
        }
        return left;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        int last, preLast;
        
        for (auto& i: tokens) {
            if (isSign(i)) {
                last = nums.back(); nums.pop_back();
                preLast = nums.back(); nums.pop_back();
                nums.push_back(calc(preLast, last, i[0]));
            }
            else {
                nums.push_back(stoi(i));
            }
        }
        
        return nums.back();
    }
};