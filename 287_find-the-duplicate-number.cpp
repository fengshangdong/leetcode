#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int left = 1, right = nums.size()-1;
    while(left < right) {
      int cnt = 0;
      int mid = left + (right-left)/2;
      for (int i = 0; i < nums.size(); i++)
        if (nums[i] <= mid)
          cnt++;

      if (cnt <= mid)
        left = mid + 1;
      else 
        right = mid;
    }

    return right;
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  Solution solv;
  int ret = solv.findDuplicate(vec);
  printf("%d\n",ret);
}
