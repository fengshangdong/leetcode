#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> >& triangle) {
    if (triangle.empty()) {
      return 0;
    }

    /* dp初始化 */
    vector<vector<int> > dp;
    for (int i = 0; i < triangle.size(); i++) {
      dp.push_back(vector<int>());
      for (int j = 0; j < triangle[i].size(); j++) {
        dp[i].push_back(0);
      }
    }

    /* dp底层赋值, row-行数 */
    int row = triangle.size();
    for(int i = 0; i < triangle[row-1].size(); i++) {
      dp[row-1][i] = triangle[row-1][i];
    }

    /* 每次取小值,从dp底层向上累加 */
    for (int i = row-2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
      }
    }

    return dp[0][0];
  }
};

int main()
{
  vector<vector<int> > triangle;
  vector<int> one;
  vector<int> two;
  vector<int> three;
  one.push_back(3);
  two.push_back(4);
  two.push_back(2);
  three.push_back(6);
  three.push_back(3);
  three.push_back(4);
  triangle.push_back(one);
  triangle.push_back(two);
  triangle.push_back(three);

  Solution solve;
  printf("%d\n", solve.minimumTotal(triangle));
}
