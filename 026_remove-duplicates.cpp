#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int slow = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i]!=nums[i-1]) {
        slow++;
        nums[slow] = nums[i];
      }
    }
    return slow+1;
  }
};

int main() {
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  Solution solv;
  int ret = solv.removeDuplicates(vec);
  printf("%d\n",ret);
}
