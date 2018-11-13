class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i <= 11; i++)
            for (int j = 0; j <= 59; j++) 
                if (countBits(i) + countBits(j) == num)
                    res.push_back(convert(i, j));
        return res;
    }
    
    string convert(int hours, int minutes) {
        return to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
    }
    
    int countBits(int x) {
        int res = 0;
        while (x != 0) {
            if (x & 1)
                res++;
            x = x >> 1;
        }
        return res;
    }
};