class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto& i: nums) {
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end(), [](string& l, string& r) {
            return l + r > r + l;
        });

        string res = "";
        for (auto& i: arr) {
            res += i;
        }
        int remove = 0, size = (int) res.size();
        while (size - remove > 1 && res[remove] == '0') {
            remove++;
        }
        return res.substr(remove);
    }
};
