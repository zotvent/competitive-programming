class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        
        int index = 0;
        int size = pattern.size();
        
        for (int i = 0; i < queries.size(); i++) {
            index = 0;
            
            for (int j = 0; j < queries[i].size(); j++) {                
                if (index < size && queries[i][j] == pattern[index])
                    index++;
                else if (upper_case(queries[i][j])) {
                    index = -1;
                    break;
                }
            }
            
            res.push_back(index == size);
        }
        
        return res;
    }
    
    bool upper_case(char c) {
        return c >= 'A' && c <= 'Z';
    }
};