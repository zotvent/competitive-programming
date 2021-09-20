class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, start = 0;
        bool flag = true;
        
        for (int end = 1; end < arr.size(); end++) {
            if (arr[end - 1] == arr[end]) {
                start = end;
            }
            else if (end % 2 == 0) {
                if (flag && arr[end - 1] < arr[end]) {
                    flag = !flag;
                    start = end - 1;
                }
                else if (!flag && arr[end - 1] > arr[end]) {
                    flag = !flag;
                    start = end - 1;
                }
            }
            else {
                if (flag && arr[end - 1] > arr[end]) {
                    flag = !flag;
                    start = end - 1;
                }
                else if (!flag && arr[end - 1] < arr[end]) {
                    flag = !flag;
                    start = end - 1;
                }
            }
            
            res = max(res, end - start + 1);
        }
        
        return res;
    }
};