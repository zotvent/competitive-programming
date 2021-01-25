class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> comp = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'},
        };
        
        int l = 0, r = num.size() - 1;
        
        while (l <= r) {
            if (comp[num[l]] != num[r] || comp[num[r]] != num[l]) {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
};