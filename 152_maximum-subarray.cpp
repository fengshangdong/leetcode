#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

/*a 记录以 nums[i-1] 结尾的乘积最小值，b 记录以 nums[i-1] 结尾的乘积最大值。*/
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int a = 1, b = 1;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; ++i) {
      int aa = a * nums[i];
      int bb = b * nums[i];

      a = min(nums[i], min(aa, bb));
      b = max(nums[i], max(aa, bb));

      maxVal = max(maxVal, b);
    }
    return maxVal;
  }
};

int main() {
  return 0;
}
