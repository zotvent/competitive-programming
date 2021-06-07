class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        vector<vector<string>> result;
        const int n = products.size();
        int start, prevStart = 0;
        string prefix;

        sort(products.begin(), products.end());

        for (char &c: searchWord) {
            prefix.push_back(c);
            start = lower_bound(products.begin() + prevStart, products.end(), prefix) - products.begin();
            result.push_back({});
            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++) {
                result.back().push_back(products[i]);
            }
            prevStart = start;
        }

        return result;
    }
};