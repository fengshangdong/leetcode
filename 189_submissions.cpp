#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (nums.empty()) return;

    int len = nums.size();
    int realk = k % len;
    reverse(nums, 0, len-1);
    reverse(nums, 0, realk-1);
    reverse(nums, realk, len-1);
  }

  void reverse(vector<int>& nums, int begin, int end) {
    while (begin < end) {
      swap(nums[begin++], nums[end--]);
    }
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(7);

  for (int i = 0; i < vec.size(); i++)
    printf("%d ",vec[i]);
  printf("\n");

  Solution solv;
  solv.rotate(vec, 113);
  for (int i = 0; i < vec.size(); i++)
    printf("%d ",vec[i]);
  printf("\n");
}
