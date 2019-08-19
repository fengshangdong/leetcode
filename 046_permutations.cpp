#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  vector<vector<int> > permute(vector<int>& nums) {
    dfs(nums,0);
    return res;
  }

  void dfs(vector<int>& nums, int begin) {
    if (begin == nums.size()-1)
      res.push_back(nums);

    for (int i = begin; i < nums.size(); i++) {
      swap(nums[begin],nums[i]);
      dfs(nums,begin+1);
      swap(nums[begin],nums[i]);
    }
  }

private:
  vector<vector<int> > res;
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  Solution solv;
  vector<vector<int> > res = solv.permute(vec);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }

}
