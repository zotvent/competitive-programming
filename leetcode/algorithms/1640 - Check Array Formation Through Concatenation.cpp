class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int head = 0;
        
        for (int i = 0; i < pieces.size(); i++) {
            head = 0;
            while (head < arr.size() && arr[head] != pieces[i][0]) {
                head++;
            }
            
            for (int j = 0; j < pieces[i].size(); j++) {
                if (j + head == arr.size() || arr[j + head] != pieces[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};