template <typename T>
struct Heap {

private:

    int size;
    int val[N];

    int sift_up(int pos) {
        int p = (pos - 1) / 2;

        if (val[p] < val[pos]) {
            swap(val[p], val[pos]);
            return sift_up(p);
        }
        
        return pos;
    }

    int sift_down(int pos) {
        int ch1 = 2 * pos + 1;
        int ch2 = 2 * pos + 2;

        if (ch1 < size) {
            if (ch2 < size) {
                if (val[ch1] >= val[ch2] && val[ch1] > val[pos]) {
                    swap(val[ch1], val[pos]);
                    return sift_down(ch1);
                }
                else if (val[ch2] >= val[ch1] && val[ch2] > val[pos]) {
                    swap(val[ch2], val[pos]);
                    return sift_down(ch2);
                }
            }
            else {
                if (val[ch1] > val[pos]) {
                    swap(val[pos], val[ch1]);
                    return sift_down(ch1);
                }
            }
        }

        return pos;
    }

public:

    Heap() {
        size = 0;
    }

    int insert(int x) {
        val[size] = x;
        int index = sift_up(size);
        size++;
        return index;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << val[i] << ' ';
        }
        cout << endl;
    }

    int increase_priority(int index, int x) {
        val[index] += x;
        return sift_up(index);
    }

    int decrease_priority(int index, int x) {
        val[index] -= x;
        return sift_down(index);
    }

    int get_max() {
        return val[0];
    }

    int extract_max() {
        size--;
        val[0] = val[size];
        return sift_down(0);
    }

};
