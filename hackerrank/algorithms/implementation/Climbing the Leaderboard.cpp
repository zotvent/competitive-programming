#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    stack<int> scores;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (scores.empty() || (!scores.empty() && scores.top() != temp))
            scores.push(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        while (!scores.empty()) {
            if (scores.top() > temp)
                break;
            scores.pop();
        }
        cout << scores.size()+1 << endl;
    }
    return 0;
}
