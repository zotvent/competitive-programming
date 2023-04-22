class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        for (auto& i: s) {
            if (!brackets.empty() && m[i] == brackets.top()) {
                brackets.pop();
            }
            else brackets.push(i);
        }
        return brackets.empty();
    }
};
