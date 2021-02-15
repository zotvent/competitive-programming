class SparseVector {
    unordered_map<int, int> mapping;
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                mapping[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        unordered_map<int, int> me = getMapping();
        unordered_map<int, int> other = vec.getMapping();
        
        for (auto it = me.begin(); it != me.end(); it++) {
            if (other.count(it->first) > 0) {
                res += it->second * other[it->first];
            }
        }
        
        return res;
    }
    
    unordered_map<int, int> getMapping() {
        return mapping;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);