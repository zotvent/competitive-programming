class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        map<int, int> right;
        vector<int> m(arr.size()+1);
        m[m.size()-1] = (int) 1e9;

        for (int i = 0; i < arr.size(); i++)
            right[arr[i]] = i;
        m[arr.size()-1] = arr[arr.size()-1];
        for (int i = arr.size()-2; i >= 0; i--)
            m[i] = min(arr[i], m[i+1]);

        for (int i = 0; i < arr.size(); i++) {
            int mini = m[i];
            int maxi = arr[i];
            int index = (mini == maxi) ? i : right[mini];

            for (int j = i+1; j <= index; j++)
                maxi = max(maxi, arr[j]);

            while (index < arr.size() && maxi > m[index+1]) {
                int temp = right[m[index+1]];
                for (int j = index+1; j <= temp; j++)
                    maxi = max(maxi, arr[j]);
                index = temp;
            }

            res++;
            i = index;
        }
        return res;
    }
};