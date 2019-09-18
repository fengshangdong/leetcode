#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    vector<int> tmp(nums.begin(), nums.end());
    int n = nums.size();
    int k = (n+1)>>1;
    int j = n;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i <n; i++) {
      nums[i] = i&1 ? tmp[--j]:tmp[--k];
    }
  }
};

int main() {
  return 0;
}
