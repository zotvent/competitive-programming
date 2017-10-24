class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
            dict[nums[i]]++;
        int res = 0;
        for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++) 
            if (dict.count(it->first+1))
                res = max(res, it->second + dict[it->first + 1]);
        return res;
    }
};