#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>

#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int, int>

const int inf = 1e9;
const int N = 9;
const int mod = 16714589;
const int MAX = 2500;

using namespace std;

int n, m, r;
char c, myRank, suit;
int myCard[4][N], card[4][N];

int suitToInt(char c) {
    if (c == 'S') return 0;
    else if (c == 'C') return 1;
    else if (c == 'D') return 2;
    else return 3;
}

int rankToInt(char c) {
    if (c == 'T') return 4;
    else if (c == 'J') return 5;
    else if (c == 'Q') return 6;
    else if (c == 'K') return 7;
    else if (c == 'A') return 8;
    else return c - '6';
}

void input() {
    cin >> n >> m >> c;
    r = suitToInt(c);
    for (int i = 1; i <= n; i++) {
        cin >> myRank >> suit;
        myCard[suitToInt(suit)][rankToInt(myRank)] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> myRank >> suit;
        card[suitToInt(suit)][rankToInt(myRank)] = 1;
    }
}

int solve() {
    //not trump cards
    for (int i = 0; i < 4; i++) {
        if (i == r) continue;

        for (int j = 0; j < N; j++) {
            if (card[i][j]) {
                bool found = false;
                //same suit
                for (int k = j+1; k < N; k++) {
                    if (myCard[i][k]) {
                        myCard[i][k] = 0;
                        found = true;
                        break;
                    }
                }

                //trump suit
                if (!found) {
                    for (int k = 0; k < N; k++) {
                        if (myCard[r][k]) {
                            myCard[r][k] = 0;
                            found = true;
                            break;
                        }
                    }
                }

                if (!found) return 0;
            }
        }
    }

    //only trump card
    for (int i = 0; i < N; i++) {
        if (card[r][i]) {
            bool found = false;

            for (int j = i+1; j < N; j++) {
                if (myCard[r][j]) {
                    myCard[r][j] = 0;
                    found = true;
                    break;
                }
            }

            if (!found) return 0;
        }
    }

    return 1;
}

int main() {
    input();
    int ans = solve();
    cout << (ans ? "YES" : "NO");
    return 0;
}