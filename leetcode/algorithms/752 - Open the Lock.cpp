class Solution {
    
    int nextMove(int cur, int index, int dif, vector<int>& nums) {
        for (int i = 3; i >= 0; i--) {
            nums[i] = cur % 10;
            cur /= 10;
        }
        nums[index] = (nums[index] + dif + 10) % 10;
        
        return nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
    }
    
public:
    int openLock(vector<string>& deadends, string target) {
        const int n = (int) 1e4;
        vector<int> m(n, INT_MAX), used(n, 0), nums(4);
        queue<int> q;
        int cur, next, tar = stoi(target);
        
        for (auto& i: deadends) {
            used[stoi(i)] = 1;
        }
        
        if (!used[0]) {
            q.push(0);
            used[0] = 1;
            m[0] = 0;
        }
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            if (cur == tar) break;
            
            for (int i = 0; i < 4; i++) {
                for (int j = -1; j <= 1; j += 2) {
                    next = nextMove(cur, i, j, nums);
                    
                    if (!used[next]) {
                        used[next] = 1;
                        m[next] = m[cur] + 1;
                        q.push(next);
                    }
                }
            }
        }
        
        return m[tar] == INT_MAX ? -1: m[tar];
    }
};