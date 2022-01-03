class Leaderboard {
    unordered_map<int, int> scores;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (scores.count(playerId)) {
            scores[playerId] += score;
        }
        else {
            scores[playerId] = score;
        }
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (auto& i: scores) {
            heap.push(i.second);
            if (heap.size() > K) {
                heap.pop();
            }
        }
        
        int res = 0;
        while (!heap.empty()) {
            res += heap.top();
            heap.pop();
        }
        return res;
    }
    
    void reset(int playerId) {
        scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */