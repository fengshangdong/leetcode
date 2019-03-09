#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
    int row = nums.size();
    int col = nums[0].size();
    int count = row * col;
    if (count != r * c) {
      return nums;
    }

    /* count/col取行数, count%col取列数 */
    vector<vector<int> >res(r, vector<int>(c));
    for (int i = 0; i < count; i++) {
      res[i/c][i%c] = nums[i/col][i%col];
    }

    return res;
  }
};

int main()
{
  int arr[2][2] = {{1,2}, {3,4}};
  vector<vector<int> > nums(2, vector<int>(2));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      nums[i][j] = arr[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", nums[i][j]);
    }
    printf("\n");
  }
  printf("\n");


  Solution solve;
  vector<vector<int> > res = solve.matrixReshape(nums, 1, 4);
  printf("%d ", res[0][0]);
  printf("%d ", res[0][1]);
  printf("%d ", res[0][2]);
  printf("%d ", res[0][3]);
}
