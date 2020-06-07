class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        
        unordered_map<string, int> m;
        int index;
        int mn = INT_MAX;
        
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        
        for (int i = 0; i < list2.size(); i++) {
            if (m.count(list2[i]) > 0) {
                index = m[list2[i]];
                
                if (i + index <= mn) {
                    if (i + index < mn) {
                        res.clear();
                        mn = i + index;
                    }
                    res.push_back(list2[i]);
                }
            }
        }
        
        return res;
    }
};