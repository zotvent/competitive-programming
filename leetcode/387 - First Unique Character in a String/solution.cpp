class Solution {
public:
    int firstUniqChar(string s) {
        pair<int, int> p[26];
        for (int i = 0; i < 26; i++) p[i] = make_pair(0, 0);
        
        for (int i = 0; i < s.length(); i++) {
            int j = (int) (s[i]-'a');
            p[j].first++;
            p[j].second = i;
        }
        
        int ans = -1, pos = (int) 1e9;
        for (int i = 0; i < 26; i++)
            if (p[i].first == 1 && p[i].second < pos) {
                pos = p[i].second;
                ans = pos;
            }
        return ans;
    }
};