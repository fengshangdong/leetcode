#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> >& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rows(m);
    vector<int> columns(n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows[i] = 1;
          columns[j] = 1;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (rows[i] || columns[j])
          matrix[i][j] = 0;
      }
    }
  }
};

int main() {
  return 0;
}
