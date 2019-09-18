#include <limits.h>
#include <vector>
#include <string>
using namespace std;
/* a 始终记录最小元素，b 为某个子序列里第二大的数。
 *
 * 接下来不断更新 a，同时保持 b 尽可能的小。
 *
 * 如果下一个元素比 b 大，说明找到了三元组。*/
class Solution {
  public:
    bool increasingTriplet(vector<int>& nums) {
      int a = INT_MAX;
      int b = INT_MAX;

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] <= a) {
          a = nums[i];
        } else if (nums[i] <= b) {
          b = nums[i];
        } else {
          return true;
        }
      }
      return false;
    }
};

int main(){
  return 0;
}

