#include <vector>
#include <stdio.h>
using namespace std;

/* 先上下交换再对角交换 */
class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    for (int i = 0, j = n-1; i < j; i++,j--)
        swap(matrix[i],matrix[j]);

    for(int i = 0;i < n;++i)
      for(int j = 0;j < i;++j)
        swap(matrix[i][j],matrix[j][i]);
  }
};

int main(){
  //略
  return 0;
}
