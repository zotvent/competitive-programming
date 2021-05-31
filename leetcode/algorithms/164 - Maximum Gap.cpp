class Solution {
    
    struct Bucket {
        bool used = false;;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
    };
    
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int mini = *min_element(nums.begin(), nums.end()),
            maxi = *max_element(nums.begin(), nums.end());
        
        int bucketSize = max(1, (maxi - mini) / ((int) nums.size() - 1));
        int bucketNum = (maxi - mini) / bucketSize + 1;
        vector<Bucket> buckets(bucketNum);
        int id;
        
        for (auto& num: nums) {
            id = (num - mini) / bucketSize;
            buckets[id].used = true;
            buckets[id].minVal = min(num, buckets[id].minVal);
            buckets[id].maxVal = max(num, buckets[id].maxVal);
        }
        
        int prevBucketMax = mini, res = 0;
        
        for (auto& bucket: buckets) {
            if (!bucket.used) continue;
            
            res = max(res, bucket.minVal - prevBucketMax);
            prevBucketMax = bucket.maxVal;
        }
        
        return res;
    }
};