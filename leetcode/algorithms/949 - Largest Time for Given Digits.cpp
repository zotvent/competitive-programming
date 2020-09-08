class Solution {
    
    void permutate(vector<int>& A, int start, int& maxTime) {
        if (start == A.size()) {
            buildTime(A, maxTime);
        }
        
        for (int i = start; i < A.size(); i++) {
            swap(A[i], A[start]);
            permutate(A, start + 1, maxTime);
            swap(A[i], A[start]);
        }
    }
    
    void buildTime(vector<int>& A, int& maxTime) {
        int hour = A[0] * 10 + A[1];
        int minute = A[2] * 10 + A[3];
        
        if (hour < 24 && minute < 60) {
            maxTime = max(maxTime, hour * 60 + minute);
        }
    }
    
public:
    string largestTimeFromDigits(vector<int>& A) {
        int maxTime = -1;
        
        permutate(A, 0, maxTime);
        
        if (maxTime == -1) {
            return "";
        }
        else {
            string res = "";
            
            res.push_back(maxTime / 60 / 10 + '0');
            res.push_back(maxTime / 60 % 10 + '0');
            res.push_back(':');
            res.push_back(maxTime % 60 / 10 + '0');
            res.push_back(maxTime % 60 % 10 + '0');
            
            return res;
        }
    }
};