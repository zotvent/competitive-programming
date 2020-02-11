class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
      vector<int> res = A;

      int odd = 1;

      for (int even = 0; even < res.size(); even += 2) {
          if (res[even] % 2 == 1) {
              while (res[odd] % 2 == 1) {
                  odd += 2;
              }
              swap(res[even], res[odd]);
          }
      }

      return res;
    }
};
