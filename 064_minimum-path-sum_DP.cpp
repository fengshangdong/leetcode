#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int> >& grid) {
    int row = grid.size();
    int col = grid[0].size();

    /* 确定dp矩阵上面和左面每个元素的值 */
    vector<vector<int> >dp(row, vector<int>(col));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < col; i++) {
      dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for (int j = 1; j < row; j++) {
      dp[j][0] = dp[j-1][0] + grid[j][0];
    }

    /* 取上面或者左边的较小值 */
    for(int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
      }
    }

    return dp[row-1][col-1];
  }
};

int  main()
{
  int arr[3][3] = { {1,3,1}, {1,5,1}, {4,2,1} };
  vector<vector<int> >grid;
  for (int i = 0; i < 3; i++) {
    grid.push_back(vector<int>());
    for (int j = 0; j < 3; j++) {
      grid[i].push_back(arr[i][j]);
    }
  }

  Solution solve;
  printf("%d\n", solve.minPathSum(grid));
}
