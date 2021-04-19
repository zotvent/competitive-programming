class Solution {

    void connect(vector<int>& v, int left, int right) {
    	left = parent(v, left);
    	right = parent(v, right);
    	
    	if (left != right) {
    		v[max(left, right)] = min(left, right);
    	}
    }

    int parent(vector<int>& v, int id) {
    	return v[id] == -1 ? id : v[id] = parent(v, v[id]);
    }
    
public:
    string smallestEquivalentString(string A, string B, string S) {
    	string res = "";
        vector<int> v(26, -1);
        
        for (int i = 0; i < A.size(); i++) {
            connect(v, A[i] - 'a', B[i] - 'a');
        }
        for (auto& c: S) {
            res.push_back(parent(v, c - 'a') + 'a');
        }
        
        return res;
    }
};