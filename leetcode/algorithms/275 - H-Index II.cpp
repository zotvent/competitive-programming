class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        
        if (citations[0] >= citations.size()) {
            return citations.size();
        }
        
        int res = 0;
        int size = citations.size();
        
        int l = 0;
        int r = size - 1;
        int m;
        
        while (l <= r) {
            m = l + (r - l) / 2;
            
            if (citations[m] >= size - m) {
                res = max(res, size - m);
            }
            
            if (citations[m] == size - m) {
                l = m + 1;
            }
            else if (citations[m] < size - m) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        return res;
    }
};