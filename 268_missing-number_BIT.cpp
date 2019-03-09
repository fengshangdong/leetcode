#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    /* ^是异或位运算符, 0^1=1  0^1^1=0 */
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      res ^= i;
      res ^= nums[i];
    }

    return res;
  }
};

int main() {
  int arr[] = {9,6,4,2,3,5,7,0,1};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.missingNumber(vec));
}
