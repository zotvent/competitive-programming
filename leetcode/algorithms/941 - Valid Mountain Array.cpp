class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        
        const int n = arr.size();
        int left = 0;
        int right = n - 1;
        
        while (left < n - 1 && arr[left] < arr[left + 1]) left++;
        while (right > 0 && arr[right - 1] > arr[right]) right--;
        
        return left == right && left > 0 && right < n - 1;
    }
};