void selectionSortInc(vector<int> &a) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

void selectionSortDesc(vector<int> &a) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max])
                max = j;
        }
        swap(a[i], a[max]);
    }
}
