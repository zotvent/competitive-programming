class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        
        for (auto email: emails) {
            string temp = "";
            bool foundPlus = false;
            bool foundAt = false;
            
            for (int i = 0; i <= email.size(); i++) {
                if (email[i] == '+')
                    foundPlus = true;
                else if (email[i] == '@') {
                    foundAt = true;
                    foundPlus = false;
                }
                
                if ((!foundAt && email[i] != '.' && !foundPlus) || foundAt)
                    temp += email[i];
            }
            s.insert(temp);
        }
        
        return s.size();
    }
};