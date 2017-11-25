#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_min(vector<int> &v) {
    int res = v[0];
    for (int i = 1; i < v.size(); i++)
        res = min(res, v[i]);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    while (arr.size() > 0) {
        cout << arr.size() << endl;
        int lowest = find_min(arr);
        vector<int> temp;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] > lowest)
                temp.push_back(arr[i]-lowest);
        arr = temp;
    }
    return 0;
}
