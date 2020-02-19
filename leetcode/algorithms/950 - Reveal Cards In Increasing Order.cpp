class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> res = deck;
        
        sort(res.begin(), res.end());
        
        deque<int> q;
        int tmp;
        
        for (int i = res.size() - 1; i >= 0; i--) {
            if (!q.empty()) {
                tmp = q.back();
                q.pop_back();
                q.push_front(tmp);
            }
            q.push_front(res[i]);
        }
        
        tmp = 0;
        while (!q.empty()) {
            res[tmp++] = q.front();
            q.pop_front();
        }
        
        return res;
    }
};