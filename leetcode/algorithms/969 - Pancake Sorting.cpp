class Solution {
    
    void reverse(vector<int>& v, int start, int end) {
        while (start < end) {
            swap(v[start++], v[end--]);
        }
    }
    
    int find(vector<int>& v, int target) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;

        const int n = A.size();
        int index;
        
        for (int i = A.size(); i > 0; i--) {
            index = find(A, i);
            
            if (index == i - 1) {
                continue;
            }
            
            if (index > 0) {
                res.push_back(index + 1);
                reverse(A, 0, index);
            }
            
            res.push_back(i);
            reverse(A, 0, i - 1);
        }
        
        for (auto& i: A) cout << i << ' '; cout << endl;
        
        return res;
    }
};