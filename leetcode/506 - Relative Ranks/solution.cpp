class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> temp = nums;
        
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        
        string medal[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        map<int, string> m;
        int cnt = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (cnt < 3) m[temp[i]] = medal[cnt];
            else m[temp[i]] = to_string(i+1);
            
            cnt++;
        }
        
        vector<string> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back(m[nums[i]]);
        return v;
    }
};