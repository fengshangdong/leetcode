#include <vector>
#include <stdio.h>
using namespace std;

/* 除自身以外数组的乘积 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.empty())
      return std::vector<int>();

    std::vector<int> psum(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i){
      psum[i] = psum[i-1] * nums[i-1];
    }

    int temp = 1;
    for(int j = nums.size()-1; j >= 0; --j){
      psum[j] = psum[j] * temp;
      temp = temp * nums[j];
    }
    return psum;
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  for (int i = 0; i < vec.size(); i++)
    printf("%d ", vec[i]);
  printf("\n");

  Solution solv;
  vector<int> res = solv.productExceptSelf(vec);
  for (int i = 0; i < res.size(); i++)
    printf("%d ", res[i]);
  printf("\n");
}
