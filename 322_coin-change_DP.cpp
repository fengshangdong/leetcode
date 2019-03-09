#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i >= coins[j] && dp[i - coins[j]] != -1) {
          if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
            dp[i] = dp[i - coins[j]] + 1;
          }
        }
      }
    }

    return dp[amount];
  }
};

int main()
{
  int amount = 11;
  vector<int> coins;
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(5);

  Solution solve;
  printf("%d\n", solve.coinChange(coins, amount));
}
