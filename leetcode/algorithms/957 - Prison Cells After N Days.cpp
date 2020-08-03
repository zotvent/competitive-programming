class Solution {
    
    int key(vector<int>& v) {
        int res = 0;
        
        for (auto& i: v) {
            res <<= 1;
            res |= i;
        }
        
        return res;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {        
        unordered_map<int, int> seen;
        
        vector<int> next;
        int size = cells.size();
        
        while (N > 0) {
            seen[key(cells)] = N--;
            next.assign(size, 0);
            
            for (int i = 1; i < size - 1; i++) {
                next[i] = (cells[i - 1] == cells[i + 1]);
            }
            
            cells = next;
            
            if (seen.count(key(cells)) > 0) {
                N %= (seen[key(cells)] - N);
            }
        }
        
        return cells;
    }
};