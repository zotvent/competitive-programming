class Solution {
    
    void backtrack(int num, int n, vector<int>& res) {
        if (num > n) {
            return;
        }
        
        res.push_back(num);
                
        for (int i = 0; i < 10; i++) {
            backtrack(num * 10 + i, n, res);
        }
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        
        for (int i = 1; i < 10; i++) {
            backtrack(i, n, res);
        }
        
        return res;
    }
};