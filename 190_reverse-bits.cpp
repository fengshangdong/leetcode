#include <stdint.h>
#include <vector>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    vector<int> bits;
    for(int i=0;i<32;i++)
    {
      bits.push_back(n%2);
      n/=2;
    }
    uint32_t m=0;
    for(int i=0;i<32;i++)
    {
      m=2*m+bits[i];
    }
    return m;
  }
};

int main() {
  return 0;
}
