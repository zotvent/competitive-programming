class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        auto pos = str.find("6");
        if (pos != string::npos) {
            str[pos] = '9';
        }
        return stoi(str);
    }
};