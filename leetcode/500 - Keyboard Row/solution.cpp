class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        
        int letter[256];
        string q = "qwertyuiop";
        string a = "asdfghjkl";
        string z = "zxcvbnm";
        for (int i = 0; i < q.length(); i++) letter[(int) tolower(q[i])] = 1;
        for (int i = 0; i < a.length(); i++) letter[(int) tolower(a[i])] = 2;
        for (int i = 0; i < z.length(); i++) letter[(int) tolower(z[i])] = 3;
        
        for (int i = 0; i < words.size(); i++) {
            int first = letter[(int) tolower(words[i][0])];
            bool ok = true;
            for (int j = 1; j < words[i].length(); j++) {
                int temp = letter[(int) tolower(words[i][j])];
                if (temp != first) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) ans.push_back(words[i]);
        }
        return ans;
    }
};