#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++){
      res = res ^ nums[i];
    }

    return res;
  }
};

int main()
{
  vector<int> vec;
  vec.push_back(3);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(5);
  vec.push_back(1);
  vec.push_back(1);
  Solution solv;
  int ret = solv.singleNumber(vec);
  printf("ret = %d\n", ret);
}
