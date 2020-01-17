class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> prev;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            m[nums2[i]] = -1;
            
            if (prev.empty()) prev.push(nums2[i]);
            else {
                while (!prev.empty() && prev.top() < nums2[i]) {
                    prev.pop();
                }
                
                if (!prev.empty()) {
                    m[nums2[i]] = prev.top();
                }
                
                prev.push(nums2[i]);
            }
        }
        
        vector<int> res;
        
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(m[nums1[i]]);
        }
        
        return res;
    }
};