#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
      int res = 0;
      int size = A.size();
      if (size == 0) return 0;
      std::map<int, int> map;

      for (int i = 0; i < size; i ++) 
        for (int j = 0; j < size; j++) 
          ++map[A[i] + B[j]];

      for (int i = 0; i < size; i ++) 
        for (int j = 0; j < size; j++) 
          res += map[-C[i]-D[j]];

      return res;
    }
};

int main() {
  return 0;
}
