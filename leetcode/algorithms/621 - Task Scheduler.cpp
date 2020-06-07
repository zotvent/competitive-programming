class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        
        unordered_map<char, int> m;
        int maxFrequency = 0;
        
        for (auto& c: tasks) {
            m[c]++;
            maxFrequency = max(maxFrequency, m[c]);
        }
        
        res = (maxFrequency - 1) * (n + 1);
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == maxFrequency) {
                res++;
            }
        }
            
        return max((int) tasks.size(), res);
    }
};