class Solution {
public:
    vector<int> gridIllumination(int N, vector< vector<int> >& lamps, vector< vector<int> >& queries) {
        vector<int> res;
        vector<int> on(lamps.size(), 1);

        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int found = 0;

            // search
            for (int j = 0; j < lamps.size(); j++) {
                int lx = lamps[j][0];
                int ly = lamps[j][1];

                if (on[j] && (lx == x || ly == y || (lx - x == ly - y) || (x - lx == ly - y))) {
                    found = 1;
                }

                if (x - 1 <= lx && lx <= x + 1 && y - 1 <= ly && ly <= y + 1) {
                    on[j] = 0;
                }
            }

            // answer
            res.push_back(found);
        }

        return res;
    }
};