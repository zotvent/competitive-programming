class Solution {
    
    vector<string> parse(string s) {
        vector<string> res;
        string cur = "";
        for (auto& c: s) {
            if (c == '+' || c == 'i') {
                res.push_back(cur);
                cur.clear();
            }
            else cur.push_back(c);
        }
        return res;
    }
    
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<string> x = parse(num1);
        vector<string> y = parse(num2);
        int a_real = stoi(x[0]);
        int a_img = stoi(x[1]);
        int b_real = stoi(y[0]);
        int b_img = stoi(y[1]);
        return to_string(a_real * b_real - a_img * b_img) + "+" + to_string(a_real * b_img + a_img * b_real) + "i";
    }
};