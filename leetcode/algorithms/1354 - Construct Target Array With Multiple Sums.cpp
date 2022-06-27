class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }
        
        priority_queue<int> q(target.begin(), target.end());
        int sum = 0;
        
        for (auto& i: target) {
            sum += i;
        }
        
        while (q.top() > 1) {
            int largest = q.top();
            q.pop();
            int x = largest - (sum - largest);
            if (x < 1) return false;
            q.push(x);
            sum = sum - largest + x;
        }
        
        return true;
    }
};