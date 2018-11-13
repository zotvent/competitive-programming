class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, pair<int, int>> m;
        
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = make_pair(1, i);
        }
        for (int i = 0; i < list2.size(); i++) {
            if (m.find(list2[i]) != m.end()) {
                m[list2[i]].first++;
                m[list2[i]].second += i;
            }
        }
        
        int least = 3000;
        for (map<string, pair<int, int>>::iterator it = m.begin(); it != m.end(); it++) {
            pair<int, int> p = it->second;
            if (p.first == 2 && p.second < least) {
                least = p.second;
            }
        }
        
        vector<string> ans;
        for (map<string, pair<int, int>>::iterator it = m.begin(); it != m.end(); it++) {
            pair<int, int> p = it->second;
            if (p.first == 2 && p.second == least) {
                ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};