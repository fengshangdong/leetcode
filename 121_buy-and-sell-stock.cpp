#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int min = prices[0];
    int max = 0;
    for (int i = 1; i < prices.size(); i++)
      if (min > prices[i])
        min = prices[i];
      else if (prices[i]-min > max)
        max = prices[i] - min;

    return max;
  }
};

int main()
{
  vector<int> vec;
  vec.push_back(7);
  vec.push_back(1);
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(6);
  vec.push_back(4);
  Solution solve;
  int ret = solve.maxProfit(vec);
  printf("%d\n",ret);
}
