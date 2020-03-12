class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        
        for (auto i: arr) {
            if (s.count(i * 2) > 0 || (i % 2 == 0 && s.count(i / 2) > 0)) {
                return true;
            }
            s.insert(i);
        }
        
        return false;
    }
};