class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        
        for (int i = 0; i < S.size(); i++) {
            if (!res.empty() && res.back() == S[i]) res.pop_back();
            else res.push_back(S[i]);
        }
        
        return res;
    }
};