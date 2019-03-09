#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums.size() == 2) {
      return std::max(nums[0], nums[1]);
    }

    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      dp[i] = std::max(dp[i-2]+nums[i], dp[i-1]);
    }

    return dp[nums.size()-1];
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);

  Solution solve;
  printf("%d\n", solve.rob(nums));
}
