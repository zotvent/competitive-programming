class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());
        
        while (q.size() > 1) {
            int s1 = q.top();
            q.pop();
            
            int s2 = q.top();
            q.pop();
            
            if (s1 != s2) {
                q.push(abs(s1 - s2));
            }
        }
        
        return q.empty() ? 0 : q.top();
    }
};