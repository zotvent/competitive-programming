class Solution {
    
    string toKey(string& email) {
        int index = 0;
        
        while (index < email.size() && email[index] != '@') {
            index++;
        }
        
        string domain = email.substr(index + 1);
        string name = "";
        
        for (int i = 0; i < index && email[i] != '+'; i++) {
            if (email[i] != '.') {
                name.push_back(email[i]);
            }
        }
        
        string key = name;
        key.push_back('@');
        key += domain;
        
        return key;
    }
    
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        
        for (auto& i: emails) {
            auto email = toKey(i);
            res.insert(email);
        }
        
        return res.size();
    }
};