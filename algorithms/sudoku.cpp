#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
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
typedef pair<int, int> pii;

const int inf = 1e9;
const int N = 1e5 + 5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

class Solution {

    int t, res;
    const int n = 9;
    vector<unordered_set<int>> rows, cols, squares;
    vector<pair<int, int>> candidates;
    vector<vector<char>> board;

    void print() {
    }

    void prepare() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    void input() {
        board.resize(n);
        for (int i = 0; i < n; i++) {
            board[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }
    }

    void output() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
                if (j % 3 == 2) cout << ' ';
            }
            cout << endl;
            if (i % 3 == 2) cout << endl;
        }
        cout << endl;
    }

    void solution() {
        solveSudoku(board);
    }

    void solveSudoku(vector<vector<char>> &board) {
        rows.resize(9);
        cols.resize(9);
        squares.resize(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j] - '0');
                    cols[j].insert(board[i][j] - '0');
                    squares[(i / 3) * 3 + j / 3].insert(board[i][j] - '0');
                } else {
                    candidates.push_back({i, j});
                }
            }
        }

        backtrack(board);
    }

    bool backtrack(vector<vector<char>> &board) {
        if (candidates.empty()) {
            return true;
        }

        pair<int, int> coordinates = candidates.back();
        int row = coordinates.first;
        int col = coordinates.second;

        candidates.pop_back();

        for (int i = 1; i <= 9; i++) {
            if (valid(row, col, i)) {
                placeCandidate(row, col, i, board);
                int a = 1;

                if (backtrack(board)) {
                    return true;
                }

                int b = 1;
                removeCandidate(row, col, i, board);
            }
        }

        candidates.push_back(coordinates);

        return false;
    }

    bool valid(int row, int col, int value) {
        int inRow = rows[row].count(value);
        int inCol = cols[col].count(value);
        int inSquare = squares[(row / 3) * 3 + col / 3].count(value);
        int sum = inRow + inCol + inSquare;

        return sum == 0;
    }

    void placeCandidate(int row, int col, int value, vector<vector<char>> &board) {
        rows[row].insert(value);
        cols[col].insert(value);
        squares[(row / 3) * 3 + col / 3].insert(value);
        board[row][col] = value + '0';
    }

    void removeCandidate(int row, int col, int value, vector<vector<char>> &board) {
        rows[row].erase(value);
        cols[col].erase(value);
        squares[(row / 3) * 3 + col / 3].erase(value);
        board[row][col] = '.';
    }

public:

    Solution() {
    }

    void solve() {
        prepare();
        cin >> t;
        while (t > 0) {
            t--;
            input();
            solution();
            output();
        }
    }
};

int main() {
    Solution s = Solution();
    s.solve();
    return 0;
}
