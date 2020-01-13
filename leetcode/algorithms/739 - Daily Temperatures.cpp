class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        
        stack<int> st;
        
        for (int i = T.size() - 1; i >= 0; i--) {
            while (!st.empty() && T[st.top()] <= T[i]) {
                st.pop();
            }
            
            if (!st.empty() && T[st.top()] > T[i]) {
                res[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return res;
    }
};