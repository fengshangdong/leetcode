#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.empty()) return false;

    int row = matrix.size(), column = matrix[0].size();
    int x = matrix.size()-1, y = 0;

    while (x >= 0 && y < column) {
      if (matrix[x][y] == target)
        return true;
      else if (matrix[x][y] > target)
        --x;
      else
        ++y;
    }
    return false;
  }
};

int main(){
  vector<vector<int> > vec;
  int arr[25] = {1,   4,  7, 11, 15, 2,   5,  8, 12, 19, 3,   6,  9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};

  for (int i = 0; i < 5; i++) {
    vector<int> temp;
    for (int j = 0; j < 5; j++) {
      temp.push_back(arr[i*5+j]);
    }
    vec.push_back(temp);
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%3ld ",vec[i][j]);
    }
    printf("\n");
  }

  vector<vector<int> >vec2;
  vector<int> n1;
  n1.push_back(1);
  n1.push_back(1);
  vec2.push_back(n1);

  Solution solv;
  int ret1 = solv.searchMatrix(vec, 5);
  int ret2 = solv.searchMatrix(vec2, 2);
  printf("ret1=%d, ret2=%d\n",ret1,ret2);

}
