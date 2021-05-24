class Solution {
public:
    string toLowerCase(string s) {
        for (auto& c: s) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
        return s;
    }
};