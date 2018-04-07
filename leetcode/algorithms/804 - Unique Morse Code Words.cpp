class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> res;
        string dict[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (auto word: words) {
            string s = "";
            for (int i = 0; i < word.length(); i++) {
                s += dict[word[i] - 'a'];
            }
            res.insert(s);
        }
        
        return res.size();
    }
};