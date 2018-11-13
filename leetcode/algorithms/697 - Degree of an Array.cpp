class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = 0;
        map<int, int> m;
        map<int, pair<int, int>> firstAndLastIndexes;
        for (int i = 0; i < nums.size(); i++) {
            degree = max(degree, ++m[nums[i]]);
            if (firstAndLastIndexes.find(nums[i]) == firstAndLastIndexes.end()) 
                firstAndLastIndexes[nums[i]].first = i;
            firstAndLastIndexes[nums[i]].second = i;
        }
        int res = (int) 1e9;
        for (auto it = firstAndLastIndexes.begin(); it != firstAndLastIndexes.end(); it++)
            if (m[it->first] == degree) {
                int first = it->second.first;
                int last = it->second.second;
                res = min(res, last-first+1);
            }
        return res;
    }
};