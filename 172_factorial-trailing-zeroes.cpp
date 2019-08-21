#include <stdio.h>
#include <iostream>

class Solution {
public:
  int trailingZeroes(int n) {
    int ans=0;
    while(n>=5){
      ans+=n/5;
      n/=5;
    }
    return ans;
  }
};

int main() {
  return 0;
}
