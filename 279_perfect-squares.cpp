#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
/*
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
 * 你需要让组成和的完全平方数的个数最少.
 * */

class Solution {
public:
  int numSquares(int n) {
    vector<int> vec;
    for (int i = 1; i*i <= n; i++)
      vec.push_back(i*i);

    int minlevel = 0;
    int size = vec.size();
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
      ++minlevel;
      int width = q.size();
      for (int i = 0; i < width; i++) {
        int front = q.front();
        q.pop();
        for (int j = 0; j < size; j++) {
          if (vec[j] <= front) {
            if (vec[j] == front)
              return minlevel;
            else
              q.push(front - vec[j]);
          }
        }
      }
    } //! end of while()

    return minlevel;
  }
};

int main() {
  return 0;
}
