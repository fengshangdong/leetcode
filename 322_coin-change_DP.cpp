#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++)
        if (coins[j] <= i)
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    return dp[amount] > amount ? -1 : dp[amount];
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
