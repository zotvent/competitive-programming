class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> dict;

        for (int i = 0; i < cpdomains.size(); i++) {
            int start = 0;

            while (cpdomains[i][start] != ' ') 
                start++;

            int n = stoi(cpdomains[i].substr(0, start));

            for (int j = cpdomains[i].size() - 1; j > start; j--) {
                if (cpdomains[i][j] == '.')
                    dict[cpdomains[i].substr(j + 1)] += n;
                else if (j == start + 1)
                    dict[cpdomains[i].substr(j)] += n;
            }
        }

        for (auto it = dict.begin(); it != dict.end(); it++)
            res.push_back(to_string(it->second) + " " + it->first);

        return res;
    }
};