class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        
        set<string> food;
        map<int, map<int, int>> table;
        unordered_map<string, int> m;
        
        for (auto order: orders) {
            food.insert(order[2]);
        }
        
        int cnt = 1;
        for (auto it = food.begin(); it != food.end(); it++) {
            m[*it] = cnt;
            cnt++;
        }
        
        for (auto order: orders) {
            table[stoi(order[1])][m[order[2]]]++;
        }
        
        vector<string> v;
        
        v.push_back("Table");
        for (auto i = food.begin(); i != food.end(); i++) {
            v.push_back(*i);
        }
        res.push_back(v);
        
        for (auto i = table.begin(); i != table.end(); i++) {
            v.clear();
            
            v.assign((int) food.size() + 1, "0");
            v[0] = to_string(i->first);
            
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                v[j->first] = to_string(j->second);
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};