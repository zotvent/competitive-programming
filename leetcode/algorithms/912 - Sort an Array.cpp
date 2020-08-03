class Solution {
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if (right - left < 2) {
            return;
        }
        
        int m = left + (right - left) / 2;
        mergeSort(nums, left, m);
        mergeSort(nums, m, right);
        
        int size = right - left;
        int l = left;
        int r = m;
        int cur = 0;
        vector<int> sortedNums(size);
        
        while (l < m || r < right) {
            if (l == m) {
                copy(nums, r, right, sortedNums, cur);
                break;
            }
            if (r == right) {
                copy(nums, l, m, sortedNums, cur);
                break;
            }
            
            if (nums[l] <= nums[r]) sortedNums[cur++] = nums[l++];
            else sortedNums[cur++] = nums[r++];
        }
        
        copy(sortedNums, 0, size, nums, left);
    }
    
    void copy(vector<int>& source, int sourceStart, int sourceEnd, vector<int>& target, int targetStart) {
        for (int i = sourceStart; i < sourceEnd; i++) {
            target[targetStart++] = source[i];
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res = nums;
        mergeSort(res, 0, res.size());
        return res;
    }
};