class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0, gain = 0;
        set<int> s(nums1.begin(), nums1.end());
        const int mod = (int) 1e9 + 7;
        
        for (int i = 0; i < nums1.size(); i++) {
            long long original = abs(nums1[i] - nums2[i]);
            res += original;
            if (gain < original) {
                auto it = s.lower_bound(nums2[i]);
                if (it != s.end()) gain = max(gain, original - abs(*it - nums2[i]));
                if (it != s.begin()) gain = max(gain, original - abs(*(--it) - nums2[i]));
            }
        }
        
        return (res - gain) % mod;
    }
};