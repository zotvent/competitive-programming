#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e5+5;
const int mod = 1e9 + 7;
const int MAX = 1e6;
const int shift = 4;
const int p[] = {31, 53};

class Solution {
    int t, n, k;
    string text;
    set<pair<ull, ull>> unique;
    vector<ull> p_pow[2], hash[2];
    
    void print() {
        cout << unique.size() << endl;
    }
    
    void input() {
        speed
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        cin >> t;
    }
    
    void output() {
    }
    
    void solution() {
        calc_pows(N);
        for (int j = 0; j < t; j++) {
            cin >> n >> k >> text;
            prepare();

            for (int i = 0; i < n - k + 1; i++) {
                ull cur[] = {hash[0][i + k - 1], hash[1][i + k - 1]};
                if (i) {
                    cur[0] -= hash[0][i - 1];
                    cur[1] -= hash[1][i - 1];                    
                }
                cur[0] *= p_pow[0][n - i - 1];
                cur[1] *= p_pow[1][n - i - 1];
                unique.insert(mp(cur[0], cur[1]));
            }

            print();
            unique.clear();
        }        
    }

    void calc_pows(int k) {
        // all pows of p
        p_pow[0].resize(k);
        p_pow[1].resize(k);
        
        p_pow[0][0] = 1;
        p_pow[1][0] = 1;

        for (int i = 1; i < k; i++) {
            p_pow[0][i] = p_pow[0][i - 1] * p[0];
            p_pow[1][i] = p_pow[1][i - 1] * p[1];
        }
    }

    void prepare() {
        // all hashes of text
        hash[0].resize(n);
        hash[1].resize(n);
        for (int i = 0; i < n; i++) {
            hash[0][i] = (text[i] - 'a' + 1) * p_pow[0][i];
            hash[1][i] = (text[i] - 'a' + 1) * p_pow[1][i];
            if (i) {
                hash[0][i] += hash[0][i - 1];
                hash[1][i] += hash[1][i - 1];
            }
        }
    }
    
public:
    
    Solution() {
    }
    
    void solve() {
        input();
        solution();
        output();
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}