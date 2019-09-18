#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    if (nums.empty()) {
      return vector<int>(2, -1);
    }

    int begin = binsearch_1(nums, target, 0, nums.size()-1);
    int end   = binsearch_2(nums, target, 0, nums.size()-1);
    res.push_back(begin);
    res.push_back(end);
    return res;
  }

  /*查找第一个等于target的位置*/
  int binsearch_1(vector<int>& vec, int e, int lo, int hi) {
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (e < vec[mid]) {
        hi = mid - 1;
      }
      else if (vec[mid] < e) {
        lo = mid + 1;
      }
      else {
        if (mid == lo || vec[mid-1] != e)
          return mid;
        else
          hi = mid - 1;
      }
    }

    return -1;
  }

  /*查找最后一个等于target的位置*/
  int binsearch_2(vector<int>& vec, int e, int lo, int hi) {
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (e < vec[mid]) {
        hi = mid - 1;
      }
      else if (vec[mid] < e) {
        lo = mid + 1;
      }
      else {
        if (mid == hi || vec[mid+1] != e)
          return mid;
        else
          lo = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
