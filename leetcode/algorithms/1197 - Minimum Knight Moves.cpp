class Solution {
    unordered_map<string, int> memo;
    
    int rec(int x, int y) {
        string key = to_string(x) + "," + to_string(y);
        
        if (memo.count(key)) {
            return memo[key];
        }
        
        if (x + y == 0) {
            return 0;
        }
        else if (x + y == 2) {
            return 2;
        }
        else {
            return memo[key] = min(rec(abs(x - 1), abs(y - 2)),
                                   rec(abs(x - 2), abs(y - 1))) + 1;
        }
    }
    
public:
    int minKnightMoves(int x, int y) {
        return rec(abs(x), abs(y));
    }
};