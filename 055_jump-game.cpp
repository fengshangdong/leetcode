#include <string>
#include <vector>
using namespace std;

/* 贪心算法，i表示当前位置，j表示当前可达的最远位置 */
class Solution {
public:
  bool canJump(vector<int>& nums) {
    for (int i = 0, j = 0; i <= j; i++) {
      j = max(i + nums[i], j);
      if (j >= nums.size() - 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  return 0;
}
