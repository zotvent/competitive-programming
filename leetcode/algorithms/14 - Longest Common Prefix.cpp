class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        string common = strs[0];
        int cnt = 0;
        for (int i = 1; i < strs.size(); i++) {
            cnt = 0;
            while (strs[i][cnt] == common[cnt])
                cnt++;
            common = common.substr(0, cnt);
        }
        return common;
    }
};