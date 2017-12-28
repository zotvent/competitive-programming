class Solution {
public:
    string longestWord(vector<string>& words) {
        map<string, int> dict;
        sort(words.begin(), words.end());
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i].length() == 1)
                dict[words[i]] = 1;
            
            string prev = words[i].substr(0, words[i].length()-1);
            if (dict[prev]) 
                dict[words[i]] = 1;
        }
        
        string res = "";
        int index = -1;
        
        for (int i = words.size()-1; i >= 0; i--) {
            if (dict[words[i]] && res.length() <= words[i].length())
                res = words[i];
        }
        
        return res;
    }
};