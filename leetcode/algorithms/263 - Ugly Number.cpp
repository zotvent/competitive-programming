class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        
        vector<int> dividers({5, 3, 2});
        for (int i = 0; i < dividers.size(); i++) {
            while (num % dividers[i] == 0)
                num /= dividers[i];
        }
        return num == 1;
    }
};