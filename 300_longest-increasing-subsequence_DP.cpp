#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size());
    dp[0] = 1;
    int max = dp[0];
    for (int i = 0; i < dp.size(); i++) {
      dp[i] = 1;
      /* 双层for循环判断上升子序列 */
      /* dp[i]存放数组 0..i 之间最长上升子序列的个数 */
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && dp[i] < dp[j]+1)
          dp[i] += 1;
      }

      if (max < dp[i]) {
        max = dp[i];
      }
    }

    return max;
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);

  Solution solve;
  printf("%d\n", solve.lengthOfLIS(nums));
}
