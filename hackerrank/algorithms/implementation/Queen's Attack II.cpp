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

bool valid(int x, int y, int n) {
    return x > 0 && y > 0 && x <= n && y <= n;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
    //clock-wise directions
    vector<int> dir(8, -1);
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        // your code goes here
        if (rQueen == rObstacle) {
            if (cQueen > cObstacle)
                dir[6] = (dir[6] == -1 ? cObstacle : max(dir[6], cObstacle));
            else
                dir[2] = (dir[2] == -1 ? cObstacle : min(dir[2], cObstacle));
        }
        if (cQueen == cObstacle) {
            if (rQueen > rObstacle)
                dir[0] = (dir[0] == -1 ? rObstacle : max(dir[0], rObstacle));
            else
                dir[4] = (dir[4] == -1 ? rObstacle : min(dir[4], rObstacle));
        }
        int dx = rObstacle - rQueen;
        int dy = cObstacle - cQueen;
        if (abs(dx) == abs(dy)) {
            if (dx > 0 && dy > 0)
                dir[3] = (dir[3] == -1 ? rObstacle : min(dir[3], rObstacle));
            else if (dx > 0 && dy < 0)
                dir[5] = (dir[5] == -1 ? rObstacle : min(dir[5], rObstacle));
            else if (dx < 0 && dy > 0)
                dir[1] = (dir[1] == -1 ? rObstacle : max(dir[1], rObstacle));
            else
                dir[7] = (dir[7] == -1 ? rObstacle : max(dir[7], rObstacle));
        }
    }
        
    int cnt = 0;
    
    //U R D L
    cnt += (dir[0] == -1 ? rQueen-1 : abs(rQueen-dir[0])-1);
    cnt += (dir[2] == -1 ? n-cQueen : abs(dir[2]-cQueen)-1);
    cnt += (dir[4] == -1 ? n-rQueen : abs(dir[4]-rQueen)-1);
    cnt += (dir[6] == -1 ? cQueen-1 : abs(cQueen-dir[6])-1);
    //UR DR DL UL
    cnt += (dir[1] == -1 ? min(rQueen-1, n-cQueen) : abs(rQueen-dir[1])-1);
    cnt += (dir[3] == -1 ? min(n-rQueen, n-cQueen) : abs(dir[3]-rQueen)-1);
    cnt += (dir[5] == -1 ? min(n-rQueen, cQueen-1) : abs(dir[5]-rQueen)-1);
    cnt += (dir[7] == -1 ? min(rQueen-1, cQueen-1) : abs(rQueen-dir[7])-1);
    
    cout << cnt;
    return 0;
}
