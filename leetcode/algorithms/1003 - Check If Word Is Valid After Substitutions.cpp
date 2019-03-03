class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        
        for (int i = 0; i < S.size(); i++) {
            st.push(S[i]);
            
            if (st.size() >= 3) {
                char third = st.top(); st.pop();
                char second = st.top(); st.pop();
                char first = st.top(); st.pop();
                
                if (first != 'a' || second != 'b' || third !='c') {
                    st.push(first);
                    st.push(second);
                    st.push(third);
                }
            }
        }
        
        return st.empty();
    }
};