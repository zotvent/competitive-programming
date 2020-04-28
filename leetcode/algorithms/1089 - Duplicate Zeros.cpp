class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        deque<int> q;
        
        bool found = false;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                found = true;
            }
            
            if (found) {
                q.push_back(arr[i]);
                if (arr[i] == 0) q.push_back(arr[i]);
                
                arr[i] = q.front();
                q.pop_front();
            }
        }
    }
};