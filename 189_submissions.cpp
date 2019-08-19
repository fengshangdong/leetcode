#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    if (size == 0 || size == 1) return;
    if(k>size && k%size==0) return;
    k = k % size;
    _reverse(nums, 0, size-k-1);
    _reverse(nums, size-k, size-1);
    _reverse(nums, 0, size-1);
  }
private:
  void _reverse(vector<int>& nums, int beg, int end) {
    int i = beg, j = end;
    while (i < j)
      swap(nums[i++], nums[j--]);
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
