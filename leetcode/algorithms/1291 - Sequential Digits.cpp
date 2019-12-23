class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        int start = numberOfDigits(low);
        int end = numberOfDigits(high);
        vector<int> tmp;
        
        for (int i = start; i <= end; i++) {
            tmp = sequential(i);
            
            for (int j = 0; j < tmp.size(); j++) {
                if (low <= tmp[j] && tmp[j] <= high) {
                    res.push_back(tmp[j]);
                }
            }
        }
        
        return res;
    }
    
    int numberOfDigits(int x) {
        int res = 0;
        
        while (x > 0) {
            res++;
            x /= 10;
        }
        
        return res;
    }
    
    vector<int> sequential(int digits) {
        vector<int> res;
        
        int tmp = 0;
        
        for (int i = 1; i <= 10 - digits; i++) {
            tmp = 0;
            
            for (int j = i; j < i + digits; j++) {
                tmp *= 10;
                tmp += j;
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};