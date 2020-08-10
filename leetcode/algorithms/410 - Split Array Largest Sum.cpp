class Solution {
    
    pair<int, int> calculateGroupsAndMaxSum(vector<int>& nums, long long maxSum) {
        long long res = 0;
        int groups = 0;
        long long sum = 0;

        for (auto& i: nums) {
            sum += i;

            if (sum > maxSum) {
                sum = i;
                groups++;
            }

            res = max(res, sum);
        }
        
        // last group
        groups++;
        
        return {groups, (int) res};
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int res;
        
        // sort(nums.begin(), nums.end());
        
        long long l = nums.back();
        long long r = 0;
        for (auto& i: nums) r += i;
        
        long long mid;
        int groups, sum;
        pair<int, int> tmp;
        
        while (l < r) {
            mid = l + (r - l) / 2;
            
            tmp = calculateGroupsAndMaxSum(nums, mid);
            groups = tmp.first;
            res = tmp.second;
            
            // printf("[%d, %d] = %d\n", l, r, mid);
            // printf("groups = %d\n", groups);
            
            if (groups > m) l = mid + 1;
            else r = mid;
        }
        
        tmp = calculateGroupsAndMaxSum(nums, l);
        groups = tmp.first;
        res = tmp.second;
        
        return res;
    }
};