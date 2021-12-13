class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            
            if (arr[index] == 0) {
                return true;
            }
            
            if (arr[index] > 0) {
                if (index - arr[index]>= 0) {
                    q.push(index - arr[index]);
                }
                if (index + arr[index] < n) {
                    q.push(index + arr[index]);
                }
                arr[index] = -arr[index];
            }
        }
        
        return false;
    }
};