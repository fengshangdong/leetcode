#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[count++] = nums[i];
      }
    }

    return count;
  }
};

int main() 
{
  int arr[] = {0,1,2,2,3,0,4,2};
  vector<int> res;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    res.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.removeElement(res, 2));
}
