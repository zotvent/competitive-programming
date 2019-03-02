const int N;
int a[N];

void merge_sort(int l, int r) {
    if (r - l < 2) {
        return;
    }

    int size = r - l;
    int m = l + (r - l) / 2;

    merge_sort(l, m);
    merge_sort(m, r);

    int li = l;
    int ri = m;
    int i = 0;

    int *sorted_array = new int [size];

    while (li < m || ri < r) {
        if (li == m) {
            copy(a + ri, a + r, sorted_array + i);
            ri = r;
        }
        else if (ri == r) {
            copy(a + li, a + m, sorted_array + i);
            li = m;
        }
        else if (a[li] < a[ri]) {
            sorted_array[i++] = a[li++];
        }
        else {
            sorted_array[i++] = a[ri++];
        }
    }

    copy(sorted_array, sorted_array + size, a + l);
}

merge_sort(0, N);
