class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        
        vector<vector<int>> m(1001, vector<int>(101, 0));
        vector<int> used(1001, 0);
        
        for (int i = 0; i < items.size(); i++) {
            m[items[i][0]][items[i][1]]++;
            used[items[i][0]] = 1;
        }
        
        for (int i = 0; i < m.size(); i++) {
            if (used[i]) {
                res.push_back({i, averageTopFive(m[i])});
            }
        }
        
        return res;
    }
    
    int averageTopFive(vector<int>& v) {
        int sum = 0;
        
        int i = (int) v.size() - 1;
        int cnt = 0;
        
        while (i >= 0 && cnt < 5) {
            while (i >= 0 && v[i] == 0) {
                i--;
            }
            
            sum += i;
            v[i]--;
            cnt++;
        }
        
        return sum / 5;
    }
};