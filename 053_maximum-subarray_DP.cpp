#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = (dp[i-1] > 0) ? dp[i-1]+nums[i] : nums[i];
      /* 或者
         dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
       * */
      if (dp[i] > max) {
        max = dp[i];
      }
    }

    return max;
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(-2);
  nums.push_back(1);
  nums.push_back(-3);
  nums.push_back(4);
  nums.push_back(-1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-5);
  nums.push_back(4);

  Solution solve;
  printf("%d\n", solve.maxSubArray(nums));
}
