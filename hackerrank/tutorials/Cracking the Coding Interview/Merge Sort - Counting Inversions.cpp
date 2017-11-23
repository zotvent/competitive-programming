#include <bits/stdc++.h>

using namespace std;

long merge_sort(vector<int> &v, int left, int right) {
    long res = 0;
    
    if (left < right) {
        int middle = (left+right)/2;
        res += merge_sort(v, left, middle);
        res += merge_sort(v, middle+1, right);
        
        int leftIterator = left, rightIterator = middle+1, iterator = 0;
        vector<int> sorted(right - left + 1);
        while (leftIterator <= middle || rightIterator <= right) {
            if (v[leftIterator] <= v[rightIterator])
                sorted[iterator++] = v[leftIterator++];
            else {
                sorted[iterator++] = v[rightIterator++];
                res += middle - leftIterator + 1;
            }
            
            if (leftIterator == middle+1) {
                copy(
                     make_move_iterator(&v[rightIterator]),
                     make_move_iterator(&v[right+1]),
                     &sorted[iterator]
                );
                break;
            }
            if (rightIterator == right+1) {
                copy(
                     make_move_iterator(&v[leftIterator]),
                     make_move_iterator(&v[middle+1]),
                     &sorted[iterator]
                );
                break;
            }
        }
        copy(
             sorted.begin(),
             sorted.end(),
             &v[left]
        );
    }
    
    return res;
}

long countInversions(vector<int> &arr) {
    // Complete this function
    return merge_sort(arr, 0, arr.size()-1);
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}
