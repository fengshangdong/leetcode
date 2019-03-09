#include<vector>
#include<set>
#include<cstdio>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (res.find(nums[i]) != res.end()) {
        return true;
      }
      res.insert(nums[i]);
    }
    return false;
  }
};

int main()
{
  int arr[] = {1,2,3,4};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.containsDuplicate(vec));
}
