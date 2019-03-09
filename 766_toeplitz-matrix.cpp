#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size()-1; i++) {
      for (int j = 0; j < matrix[i].size()-1; j++) {
        if (matrix[i][j] != matrix[i+1][j+1]) {
          return false;
        }
      }
    }

    return true;
  }
};

int main() {
  int arr[3][4] = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
  vector<vector<int> > vec(3,vector<int>(4));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      vec[i][j] = arr[i][j];
    }
  }
  Solution solve;
  printf("%d\n",solve.isToeplitzMatrix(vec));
}
