#include <stdio.h>

class Solution {
public:
  int mySqrt(int x) {
    long long lo = 0, hi = x;

    while (lo < hi) {
      long long mid = (lo + hi+1) / 2;
      long long t = mid*mid;
      if (x < t)
        hi = mid-1;
      else
        lo = mid;
    }
    return lo;
  }
};

int main() {
  int x = 9;
  Solution solv;
  int ret = solv.mySqrt(x);
  printf("ret=%d\n",ret);
}
