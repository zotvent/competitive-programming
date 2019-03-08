class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        
        for (int i = 0; i < emails.size(); i++) {
            string tmp;
            bool foundPlus = false;
            bool foundAt = false;
            
            for (int j = 0; j < emails[i].size(); j++) {
                char c = emails[i][j];
                
                if (c == '@') foundAt = true;
                else if (c == '+') foundPlus = true;
                
                if (foundAt) tmp += c;
                else if (!foundPlus && c != '.') tmp += c;
            }
                
            s.insert(tmp);
        }
        
        return s.size();
    }
};