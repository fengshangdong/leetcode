#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    double myPow(double x, long long n) {
      if (n == 0)
        return 1;
      if (n < 0)
        return 1 / myPow(x, -n);
      double mid = myPow(x, n / 2);
      if (n & 1)
        return mid * mid * x;
      return mid * mid;
    }
};

int main() {
  return 0;
}
