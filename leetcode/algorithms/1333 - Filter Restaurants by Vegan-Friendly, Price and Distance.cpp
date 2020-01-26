class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;

        for (auto r: restaurants) {
            if (((veganFriendly && r[2]) || !veganFriendly) && r[3] <= maxPrice && r[4] <= maxDistance) {
                filtered.push_back(r);
            }
        }

        sort(filtered.begin(), filtered.end(), comp);

        vector<int> res;

        for (auto r: filtered) {
            res.push_back(r[0]);
        }

        return res;
    }

    static bool comp(vector<int> right, vector<int> left) {
        if (right[1] == left[1]) return right[0] > left[0];
        else return right[1] > left[1];
    }
};