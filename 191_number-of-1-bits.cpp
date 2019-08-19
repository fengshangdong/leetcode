#include <stdio.h>
#include <stdint.h>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
};

int main() {
  int n  = 9;
  Solution solv;
  int ret = solv.hammingWeight(n);
  printf("ret=%d\n",ret);
}
