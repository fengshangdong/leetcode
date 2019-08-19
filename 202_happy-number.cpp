#include <set>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    set<int> s;
    while (!s.count(n)) {
      if (n == 1) return true;
      s.insert(n);
      int sum = 0;
      while (n) {
        sum += (n%10)*(n%10);
        n = n/10;
      }
      n = sum;
    }
    return false;
  }
};

int main() {
  int n = 19;
  Solution solv;
  int ret=  solv.isHappy(n);
  printf("ret=%d\n",ret);
}
