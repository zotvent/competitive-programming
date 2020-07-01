class Solution {
    
    string generateSequence(int n) {
        string res = "";
        
        for (int i = 0; i < n; i++) {
            res.push_back(i + '1');
        }
        
        return res;
    }
    
    vector<int> generateFactorial(int n) {
        vector<int> res(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            res[i] = res[i - 1] * i;
        }
        
        return res;
    }
    
public:
    string getPermutation(int n, int k) {
        string res = "";
        
        string nums = generateSequence(n);
        vector<int> factorial = generateFactorial(n);
        int index;
        
        for (int i = 1; i <= n; i++) {
            index = (k - 1) / factorial[n - i];
            res.push_back(nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * factorial[n - i];
        }
        
        return res;
    }
};