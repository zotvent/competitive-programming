class Solution {
public:
    int calculate(string s) {        
        stack<int> nums;
        stack<char> signs;
        
        map<char, int> priority = {
            {'+', 0},
            {'-', 0},
            {'*', 1},
            {'/', 1}
        };
        
        string num = "";
        char sign;
        vector<int> last(2, 0);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            
            if (isdigit(s[i])) {
                num.push_back(s[i]);
            }
            else {
                nums.push(stoi(num));
                num.clear();
                
                while (!signs.empty() && priority[signs.top()] >= priority[s[i]]) {
                    sign = signs.top(); signs.pop();
                    last[1] = nums.top(); nums.pop();
                    last[0] = nums.top(); nums.pop();
                    nums.push(calc(last[0], last[1], sign));
                }
                
                signs.push(s[i]);
            }
        }
        
        if (!num.empty()) {
            nums.push(stoi(num));
            num.clear();
        }
        
        while (!signs.empty()) {
            sign = signs.top(); signs.pop();
            last[1] = nums.top(); nums.pop();
            last[0] = nums.top(); nums.pop();
            nums.push(calc(last[0], last[1], sign));
        }
        
        return nums.top();
    }
    
    int calc(int left, int right, char sign) {
        if (sign == '+') left += right;
        else if (sign == '-') left -= right;
        else if (sign == '*') left *= right;
        else left /= right;
        
        return left;
    }
};