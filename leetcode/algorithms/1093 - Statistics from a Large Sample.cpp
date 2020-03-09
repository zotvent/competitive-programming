class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mn = 255;
        double mx = 0;
        double mean = 0;
        double median = 0;
        double mode = 0;
        
        int cnt = 0;
        int freq = 0;
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                mn = min(mn, (double) i);
                mx = max(mx, (double) i);
                mean += i * count[i];

                if (freq < count[i]) {
                    freq = count[i];
                    mode = i;
                }
                
                cnt += count[i];
            }
        }
        
        mean /= cnt;
        int cur = 0;
        int next = 0;
        int middle = cnt / 2;
        bool even = (cnt % 2 == 0);
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                next = cur + count[i];
                
                if (cur <= middle && middle < next) {
                    median += i;
                }
                if (even && cur <= middle - 1 && middle - 1 < next) {
                    median += i;
                }

                cur = next;
            }
        }
        
        if (even) {
            median /= 2;
        }
        
        return {mn, mx, mean, median, mode};
    }
};