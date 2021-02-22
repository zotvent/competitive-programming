class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        int head = 0;
        bool less;
        
        for (auto &i: d) {
            head = 0;
            
            for (int j = 0; j < s.size(); j++) {
                if (head < i.size() && s[j] == i[head]) {
                    head++;
                }
            }
            
            less = (res.size() == i.size() && res > i);
            if (head == i.size() && (res.size() < i.size() || less)) {
               res = i;
            }
        }
        
        return res;
    }
};