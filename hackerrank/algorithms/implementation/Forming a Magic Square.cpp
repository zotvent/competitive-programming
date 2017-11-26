#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//4 9 2
//3 5 7
//8 1 6

int minimumCost(vector<vector<int>> v) {
    vector<int> res;
    int possible_combinations[8][3][3] = {
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    };
    for (int i = 0; i < 8; i++) {
        int cost = 0;
        for (int row = 0; row < 3; row++) 
            for (int col = 0; col < 3; col++) 
                if (v[row][col] != possible_combinations[i][row][col]) 
                    cost += abs(v[row][col] - possible_combinations[i][row][col]);
        res.push_back(cost);
    }
    int ans = res[0];
    for (int i = 1; i < res.size(); i++)
        ans = min(ans, res[i]);
    return ans;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
        for(int s_j = 0;s_j < 3;s_j++){
            cin >> s[s_i][s_j];
        }
    }
    //  Print the minimum cost of converting 's' into a magic square
    cout << minimumCost(s);
    return 0;
}
