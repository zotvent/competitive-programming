class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    vector<string> res;
    int i, j;
    
    vector<string> row = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    map<char, int> dict;
    for (i = 0; i < row.size(); i++)
        for (j = 0; j < row[i].size(); j++)
            dict[row[i][j]] = i + 1;
    
    for (i = 0; i < words.size(); i++) {
        int r = dict[tolower(words[i][0])];
        for (j = 1; j < words[i].size(); j++) {
            if (dict[tolower(words[i][j])] != r)
                break;
        }
        if (j == words[i].size())
            res.push_back(words[i]);
    }
    
    return res;
}
};