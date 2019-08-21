#include <vector>
#include <iostream>
#include <limits.h>

class Solution {
public:
  int reverse(int x) {
    long sum = 0;
    while( x != 0)
    {
      sum = sum * 10 + x % 10;
      if ( sum > INT_MAX || sum < INT_MIN) return 0;
      x/= 10;
    }
    return sum;
  }
};

int main()
{
  return 0;
}
