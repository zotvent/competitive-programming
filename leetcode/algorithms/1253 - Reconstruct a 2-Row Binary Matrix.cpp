class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector< vector<int> > res;
        vector<int> u, l;
        int cur;
        
        for (int i = 0; i < colsum.size(); i++) {
            cur = colsum[i];
            
            if (cur == 2) {
                u.push_back(1);
                l.push_back(1);
                upper--;
                lower--;
            }
            else if (cur == 1) {
                if (upper >= lower) {
                    u.push_back(1);
                    upper--;
                    l.push_back(0);
                }
                else {
                    l.push_back(1);
                    lower--;
                    u.push_back(0);
                }
            }
            else {
                u.push_back(0);
                l.push_back(0);
            }
        }
        
        if (upper == 0 && lower == 0) {
            res.push_back(u);
            res.push_back(l);
        }
        
        return res;
    }
};