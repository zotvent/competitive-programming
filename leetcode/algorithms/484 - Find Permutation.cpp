class Solution {
    
    void reverse(vector<int>& v, int left, int right) {
        while (left < right) {
            swap(v[left++], v[right--]);
        }
    }
    
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        
        for (int i = 1; i <= s.size() + 1; i++) {
            res.push_back(i);
        }
        
        int start;
        
        for (int i = 1; i < res.size(); i++) {
            start = i;
            
            while (i <= s.size() && s[i - 1] == 'D') {
                i++;
            }
            
            reverse(res, start - 1, i - 1);
        }
        
        return res;
    }
};