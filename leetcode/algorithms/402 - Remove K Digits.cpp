class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        
        for (auto i: num) {
            while (k > 0 && !res.empty() && res.back() > i) {
                res.pop_back();
                k--;
            }
            res.push_back(i);
        }
        
        res.resize(res.size() - k);
        
        int head = 0;
        
        while (head < res.size() && res[head] == '0') {
            head++;
        }
        
        res = res.substr(head);
        
        return (res.empty() ? "0" : res);
    }
};