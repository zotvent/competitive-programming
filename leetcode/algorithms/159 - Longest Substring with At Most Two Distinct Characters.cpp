class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        int start = 0;
        unordered_map<char, int> last;
        unordered_map<char, int>::iterator first, second;
        
        for (int i = 0; i < s.size(); i++) {
            if (last.size() == 2 && last.count(s[i]) == 0) {
                first = second = last.begin();
                second++;
                
                if (first->second < second->second) {
                    start = first->second + 1;
                    last.erase(first);
                }
                else {
                    start = second->second + 1;
                    last.erase(second);
                }
            }

            last[s[i]] = i;            
            res = max(res, i - start + 1);
        }
        
        return res;
    }
};