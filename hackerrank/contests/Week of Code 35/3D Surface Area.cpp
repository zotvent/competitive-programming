#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector < vector<int> > A) {
    // Complete this function
    int i, j;
    int h = A.size(), w = A[0].size();
    int res = h*w*2;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (j == 0)
                res += A[i][j];
            else
                res += abs(A[i][j]-A[i][j-1]);
        }
        res += A[i][w-1];
    }
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            if (j == 0)
                res += A[j][i];
            else
                res += abs(A[j][i]-A[j-1][i]);
        }
        res += A[h-1][i];
    }
    return res;
}

int main() {
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = surfaceArea(A);
    cout << result << endl;
    return 0;
}
