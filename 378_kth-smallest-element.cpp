#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  int _search(vector<int>& vec, int e) { /* 求大于e的元素位置 */
    int lo = 0, hi = vec.size()-1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (e < vec[mid])
          hi = mid - 1;
      else
        lo = mid + 1;
    }

    return lo;
  }

  // 标准 upperbound 模板。查找第一个 > target 的元素的位置。
  // 也就是 <= target 的元素的个数。
  int _search2(vector<int>& row, int target) {
    int lo = 0, hi = row.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (target < row[mid]) 
        hi = mid;
      else 
        lo = mid + 1;
    }
    return lo;
  }

  int kthSmallest(vector<vector<int> >& matrix, int k) {
    int row = matrix.size();
    if (row == 0) return -1;
    int col = matrix[0].size();
    if (col == 0) return -1;

    int lo = matrix[0][0];
    int hi = matrix.back().back();
    while (lo < hi) 
    {
      int mid = lo + (hi - lo) / 2;
      int count = 0;
      for (int i = 0; i < matrix.size(); ++i)
        count += _search(matrix[i], mid); // 大于 mid 的元素个数
      
      if (k <= count) 
        hi = mid;
      else 
        lo = mid + 1;
    }
    return lo;
  }
};

int main(){
  vector<vector<int> > vec;
  int arr[] = {1, 5, 9, 10, 11, 13, 12, 13, 15};

  for (int i = 0; i < 3; i++) {
    vector<int> temp;
    for (int j = 0; j < 3; j++) {
      temp.push_back(arr[i*3+j]);
    }
    vec.push_back(temp);
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3ld ",vec[i][j]);
    }
    printf("\n");
  }

  Solution solv;
  int ret1 = solv.kthSmallest(vec, 8);
  printf("ret1=%d\n",ret1);

}
