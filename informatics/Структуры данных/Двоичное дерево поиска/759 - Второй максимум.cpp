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
const int N = 1e5+5;
const int mod = 1743;
const int MAX = 1e6;
const int shift = 4;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* add(TreeNode* root, int x) {
    if (!root)
        return new TreeNode(x);

    if (x < root->val)
        root->left = add(root->left, x);
    else if (root->val < x)
        root->right = add(root->right, x);

    return root;
}

class Solution {
    int x, res;
    TreeNode* root;
    
    void print() {
    }
    
    void input() {
        speed
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        while(cin >> x) {
            if (x == 0) break;
            root = add(root, x);
        }
    }
    
    void output() {
        cout << res;
    }
    
    void solution() {
        while (root->right) {
            res = root->val;
            root = root->right;
        }

        res = max(res, right_most(root->left));
    }

    int right_most(TreeNode* root) {
        if (root) {
            while (root->right) 
                root = root->right;
            return root->val;
        }
        else return 0;
    }
    
public:

    Solution() {
        root = NULL;
        res = 0;
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
