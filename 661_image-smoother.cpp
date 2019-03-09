#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
    /* row-行, col-列 */
    /* 取周围8个点及自己求平均值 */
    int sum = 0;
    int row = M.size();
    int col = M[0].size();
    vector<vector<int> >mark(row, vector<int>(col));
    static const int dx[] = {0, 1, 1, 1, 0,-1,-1,-1};
    static const int dy[] = {1, 1, 0,-1,-1,-1, 0, 1};
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        int count = 1;
        int sum = M[i][j];
        for (int k = 0; k < 8; k++) {
          int newx = i + dx[k];
          int newy = j + dy[k];
          if (newx < 0 || newx >= row|| newy < 0 || newy >= col)
            continue;

          sum += M[newx][newy];
          count++;
        }
        mark[i][j] = sum / count;
      }
    }

    return mark;
  }
};

int main()
{
  int arr[5][3] = {{2,3,4}, {5,6,7}, {8,9,10}, {11,12,13},{14,15,16}};
  vector<vector<int> > vec(5, vector<int>(3));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      vec[i][j] = arr[i][j];
    }
  }

  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[i].size(); j++) {
      printf("%d\t", vec[i][j]);
    }
    printf("\n");
  }
  Solution solve;
  vector<vector<int> > res = solve.imageSmoother(vec);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      printf("%d\t", res[i][j]);
    }
    printf("\n");
  }
}
