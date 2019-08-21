#include <math.h>
using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n == 1) return true;
    else if (n == 0) return false;
    else return isPowerOfThree(n/3) && n % 3 == 0;
  }
};

int main() {
  return 0;
}
