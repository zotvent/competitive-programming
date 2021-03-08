class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s;
        const int n = candyType.size();
        
        for (auto& i: candyType) {
            s.insert(i);
        }
        
        return min(n / 2, (int) s.size());
    }
};