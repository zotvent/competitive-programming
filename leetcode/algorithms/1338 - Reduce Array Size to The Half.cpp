class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int res = 0;
        
        vector<int> v;
        int cur, cnt;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            cur = arr[i];
            cnt = 1;
            
            while (i < arr.size() - 1 && cur == arr[i + 1]) {
                i++;
                cnt++;
            }
            
            v.push_back(cnt);
        }
        
        sort(v.begin(), v.end());
        
        int i = v.size() - 1;
        cur = arr.size();
        int half = (int) arr.size() / 2;
        
        while (cur > half && i >= 0) {
            cur -= v[i];
            i--;
            res++;
        }
        
        return res;
    }
};