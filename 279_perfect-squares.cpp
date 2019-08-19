#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  int numSquares(int n) {
    vector<int> vec;
    for(int i=1;i*i<=n;++i){
      vec.push_back(i*i);
    }

    int minlen=0, size = vec.size();
    queue<int> q;//辅助队列
    q.push(n);
    while(!q.empty()){
      ++minlen;//树的高度
      int width=q.size();
      for(int j = 0; j < width; j++) {
        int temp = q.front();
        q.pop();
        for (int i=size-1;i>=0;--i) {
          if (vec[i]<=temp) {
            if (vec[i]==temp)
              return minlen;
            else
              q.push(temp-vec[i]); //减掉之后剩余的值入队
          }
        }
      }
    }

    return minlen;//循环里一定有返回值（不会执行）
  }
};

int main() {
  return 0;
}
