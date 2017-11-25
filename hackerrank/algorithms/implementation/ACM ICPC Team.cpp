#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    vector<vector<int>> table(n, vector<int>(n, 0));
    int max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (table[i][j])
                continue;
            int cnt = 0;
            for (int k = 0; k < m; k++)
                if (topic[i][k] == '1' || topic[j][k] == '1')
                    cnt++;
            table[i][j] = table[j][i] = cnt;
            max = ::max(max, cnt);
        }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (table[i][j] == max)
                cnt++;
    cout << max << endl << cnt;
    return 0;
}
